#include <bits/stdc++.h>

const int N = 1005;

int n;

struct point {
	long long x, y;

	point() {}
	point(long long _x, long long _y) : x(_x), y(_y) {
		x = _x, y = _y;
	}
	
	point operator + (const point &rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}

	point operator - (const point &rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
	
	point operator * (long long la) const {
		return point(x * la, y * la);
	}

	point operator / (long long la) const {
		return point(x / la, y / la);
	}
	
	bool operator < (const point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}

	bool operator == (const point &rhs) const {
		return x == rhs.x && y == rhs.y;
	}
};

long long dot(const point &a, const point &b) {
	return 1ll * a.x * b.x + 1ll * a.y * b.y;
}

long long cross(const point &a, const point &b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

struct line {
	point a, b;
} a[N];

bool segment_intersection(const line &a, const line &b) {
	long long t1, t2;
	t1 = cross(b.a - a.a, a.b - a.a), t2 = cross(b.b - a.a, a.b - a.a);
	if ((t1 > 0 && t2 > 0) || (t1 < 0 && t2 < 0)) return 0;
	t1 = cross(a.a - b.a, b.b - b.a), t2 = cross(a.b - b.a, b.b - b.a);
	if ((t1 > 0 && t2 > 0) || (t1 < 0 && t2 < 0)) return 0;
	return 1;
}

bool cross_point(const line &a, const line &b, point &res) {
	if (!segment_intersection(a, b)) {
		return false;
	}
	point u = a.a - b.a, v = a.b - a.a, w = b.b - b.a;
	long long p = cross(w, u), q = cross(v, w);
	if (v.x * p % q == 0 && v.y * p % q == 0) {
		res = a.a + v * cross(w, u) / cross(v, w);
		return true;
	} else {
		return false;
	}
}

long long cnt[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].a.x >> a[i].a.y >> a[i].b.x >> a[i].b.y;
		ans += abs(std::__gcd(a[i].b.x - a[i].a.x, a[i].b.y - a[i].a.y)) + 1;
	}

	for (int i = 1; i <= n; ++i) {
		cnt[i] = i * (i - 1) / 2;
	}

	std::vector<point> in;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			point res;
			if (cross_point(a[i], a[j], res)) {
				in.push_back(res);
			}
		}
	}
	std::sort(in.begin(), in.end());
	int now = 0;
	for (int i = 0; i < (int)in.size(); ++i) {
		++now;
		if (i == (int)in.size() - 1 || !(in[i] == in[i + 1])) {
			ans -= std::lower_bound(cnt + 1, cnt + 1 + n, now) - cnt - 1;
			now = 0;
		}
	}
	std::cout << ans << "\n";
}