#include <iostream>
#include <algorithm>
#include <cstring>

struct Point { long long x, y; };

long long dist(Point A, Point B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

struct Slope {
	Point A, B;
	Slope(Point a, Point b) : A(a), B(b) {}
	bool operator==(const Slope &o) const {
		if (A.x == B.x || o.A.x == o.B.x)
			return A.x == B.x && o.A.x == o.B.x && A.x == o.A.x;
		return (A.y - B.y) * (o.A.x - o.B.x) == (o.A.y - o.B.y) * (A.x - B.x);
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	Point A, B, C;

	std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	if (dist(A, B) == dist(B, C) && !(Slope(A, B) == Slope(B, C)))
		std::cout << "Yes";
	else
		std::cout << "No";

	return 0;
}