#include <bits/stdc++.h>

struct point {
	long long x, y;

	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {}

	bool operator<(const point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
};

bool check(const point &a, const point &b, const point &c) {
	return (b.y - a.y) * (c.x - b.x) > (c.y - b.y) * (b.x - a.x);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<point> a(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		a[i] = point(-x, y - 1ll * x * x);
	}
	std::sort(a.begin(), a.end());
	
	std::vector<point> sta;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && a[i].x == a[i + 1].x) {
			continue;
		}
		while ((int)sta.size() > 1 && !check(sta[sta.size() - 2], sta[sta.size() - 1], a[i])) {
			sta.pop_back();
		}
		sta.push_back(a[i]);
	}
	std::cout << (int)sta.size() - 1 << "\n";
}