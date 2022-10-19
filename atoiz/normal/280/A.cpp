#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double intersectX (double x0, double y0, double x1, double y1, double x) {
	return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
}

double intersectY (double x0, double y0, double x1, double y1, double y) {
	return x0 + (y - y0) * (x1 - x0) / (y1 - y0);
}

int main()
{
	double w, h, a;
	cin >> w >> h >> a;
	if (w < h) swap(w, h);
	if (a == 0 || a == 180) return cout << fixed << setprecision(8) << w*h << endl, 0;
	if (a == 90) return cout << fixed << setprecision(8) << h*h << endl, 0;
	a = min(a, 180 - a);

	w /= 2, h /= 2, a = a / 180 * acos(-1);
	double d = sqrt(w*w + h*h);
    double cosa = cos(a), sina = sin(a);
    double cosb = w / d, sinb = h / d;

    double x0 = d * (cosa * cosb - sina * sinb);
    double y0 = d * (sina * cosb + sinb * cosa);
    double x1 = d * (cosa * cosb + sina * sinb);
    double y1 = d * (sina * cosb - sinb * cosa);

    if (a >= atan2(h, w) * 2) {
        double tmp = intersectY(-x0, -y0, x1, y1, h) - intersectY(x0, y0, -x1, -y1, h);
        cout << fixed << setprecision(8) << (tmp * 2 * h) << endl;
    } else {
        double d1 = w - intersectY(x0, y0, x1, y1, h);
        double d2 = h - intersectX(x0, y0, x1, y1, w);
        double d3 = w - intersectY(-x0, -y0, x1, y1, -h);
        double d4 = h + intersectX(-x0, -y0, x1, y1, w);
        cout << fixed << setprecision(8) << (4 * w * h - d1 * d2 - d3 * d4) << endl;
    }
}