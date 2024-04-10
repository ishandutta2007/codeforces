#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
	double x, y;
	Point(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
};

Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator * (const double &s, const Point &a) {
	return Point(s * a.x, s * a.y);
}

double norme(const Point &a) {
	return sqrt(a.x * a.x + a.y * a.y);
}

double dist(const Point &a, const Point &b) {
	return norme(a - b);
}

double vect(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}

double scal(const Point &a, const Point &b) {
	return a.x * b.x - a.y * b.y;
}

vector<Point> points;
int nbPoints;
Point o;

double melChoix(Point a, Point b) {
	double maxChange = -dist(a, o);
	int pos = 0;
	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		if(maxChange < dist(o, points[iPoint]) - dist(a, points[iPoint])) {
			maxChange = dist(o, points[iPoint]) - dist(a, points[iPoint]);
			pos = iPoint;
		}
	}
	
	double melChange = 0;
	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		if(iPoint != pos && melChange < dist(o, points[iPoint]) - dist(b, points[iPoint])) {
			melChange = dist(o, points[iPoint]) - dist(b, points[iPoint]);
		}
	}
	
	return maxChange + melChange;
}

int main() {
	double ax, ay, bx, by, ox, oy;
	cin >> ax >> ay >> bx >> by >> ox >> oy;
	
	Point a(ax, ay);
	Point b(bx, by);
	o = Point(ox, oy);
	
	cin >> nbPoints;
	
	double somme = 0;
	for(int iPoint = 0;iPoint < nbPoints;iPoint++) {
		double x, y;
		cin >> x >> y;
		points.push_back(Point(x, y));
		somme += 2 * dist(o, points.back());
	}
	
	cout << fixed << setprecision(12);
	cout << somme - max(melChoix(a, b), melChoix(b, a)) << endl;
	
	return 0;
}