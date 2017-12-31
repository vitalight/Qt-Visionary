#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include <QPainter>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QSpinBox>

#include <vector>

//#define __RELEASE__
#define HISTORY_MAX (8)
#define TAB_OFFSET (28)

namespace Ui {
class MainWindow;
}

class ImageInfo
{
public:
    QImage *originalImage = NULL,
           *currentImage = NULL;
    QImage thumbnail;
    std::vector<QImage *> historyImages;
    int historyIndex = -1;
    int showWidth = 0, showHeight = 0;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ui_clear();
    void ui_recover();
    void ui_change_val1(int val);
    void ui_change_val2(int val);
    void ui_change_val3(int val);

    void on_actionOpen_triggered();

    void on_actionDecolor_triggered();

    void on_actionRecover_triggered();

    void on_actionExit_triggered();

    void on_actionSave_as_triggered();

    void on_actionAbout_triggered();

    void on_actionBlur_triggered();

    void on_actionSharpen_triggered();

    void on_actionDilation_triggered();

    void on_actionErosion_triggered();

    void on_actionEqualizeHistogram_triggered();

    void on_actionResize_triggered();

    void on_actionResizeLinear_triggered();

    void slot_channelSeperation();
    void on_actionChannelSeperation_triggered();

    void on_actionSpinNearest_triggered();

    void on_actionSpinLinear_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionDetectEdgeSobel_triggered();

    void on_actionDetectEdgeLaplacian_triggered();

    void on_actionDetectEdgeCanny_triggered();

    void on_actionOtsu_triggered();

    void on_actionDoubleThreshold_triggered();

    void on_actionBlurMean_triggered();

    void on_actionBlurMedian_triggered();

    void on_actionMorphologicalOpen_triggered();

    void on_actionMorphologicalClose_triggered();

    void on_switchButton_clicked();

    void on_actionSwitch_triggered();

    void on_actionCopyToAnother_triggered();

    void on_actionAdd_triggered();

    void on_actionMinus_triggered();

    void on_actionTimes_triggered();

    void on_actionCut_triggered();

    void on_actionShowHistogram_toggled(bool arg1);

    void slot_adjustHSB();
    void slot_adjustHSB_preview();
    void on_actionadjustHSB_triggered();

    void on_actionThining_triggered();

    void on_actionThickening_triggered();

    void on_actionDistanceTransform_triggered();

    void on_actionSkeletonize_triggered();

    void on_actionContrastStretch_triggered();

    void on_actionSkeletonReconstruct_triggered();

    void on_actionReconstruct_triggered();

private:
    Ui::MainWindow *ui;

    QLabel *qlabel;
    ImageInfo images[2];
    int imageIndex = 0;
    bool showHistogram = false;
    int ui_val1 = 0,
        ui_val2 = 0,
        ui_val3 = 0;
    std::vector<QWidget *> widgetList;

    QDialogButtonBox *createButtonBox();

    QImage *getCurrentImage();
    QImage *getAnotherImage();
    void setCurrentImage(QImage *image);
    void setAnotherImage(QImage *image);

    void showResponseTime();
    void showThumbnail(QImage *image);
    void showImage_without_history(QImage *image);
    void showImage(QImage *image);
    QImage autoscale(QImage *image = NULL);
    void showTip(QString str);
    void updateHistogram();
protected:
    void mouseMoveEvent(QMouseEvent* event);

};

#endif // MAINWINDOW_H
