#include <bits/stdc++.h>

const int N = 5005;

int n;

struct Point {
	int x, y;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
} a[N];

std::istream &operator>>(std::istream &in, Point &A) {
	in >> A.x >> A.y;
	return in;
}

Point operator-(const Point &A, const Point &B) {
	return Point(A.x - B.x, A.y - B.y);
}

long long dot(const Point &A, const Point &B) {
	return 1ll * A.x * B.x + 1ll * A.y * B.y;
}

bool check(Point a, Point b, Point c) {
	return dot(a - b, c - b) > 0;
}

int p[N];

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		p[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j < n; ++j) {
			if (!check(a[p[j - 1]], a[p[j]], a[p[j + 1]])) {
				std::swap(p[j], p[j + 1]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << p[i] << " \n"[i == n];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	// std::cin >> T;
	while (T--) {
		solve();
	}
}