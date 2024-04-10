#include <bits/stdc++.h>

long long a, b, c;

struct Point {
	double x, y;
} A, B;

double myabs(double a) {
	return a > 0 ? a : -a;
}

double man_dis(Point a, Point b) {
	return myabs(a.x - b.x) + myabs(a.y - b.y);
}

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calc(Point a, Point b) {
	return man_dis(A, a) + dist(a, b) + man_dis(b, B);
}

Point getx(double x) {
	return (Point){x, (-c - a * x) / b};
}

Point gety(double y) {
	return (Point){(-c - b * y) / a, y};
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(10);

	std::cin >> a >> b >> c;
	std::cin >> A.x >> A.y >> B.x >> B.y;

	if (a == 0 || b == 0) {
		std::cout << man_dis(A, B) << "\n";
		return 0;
	}

	std::cout << std::min({
		man_dis(A, B),
		calc(getx(A.x), getx(B.x)),
		calc(getx(A.x), gety(B.y)),
		calc(gety(A.y), getx(B.x)),
		calc(gety(A.y), gety(B.y))
	}) << "\n";
}