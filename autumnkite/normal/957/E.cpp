#include <bits/stdc++.h>

const int N = 100005;

int n, W;

struct Plane {
	int x, v;
} a[N];

struct Frac {
	int a, b;
	
	Frac() {}
	Frac(int _a, int _b) {
		a = _a, b = _b;
		if (b < 0) {
			a = -a, b = -b;
		}
	}
	
	bool operator < (const Frac &rhs) const {
		return 1ll * a * rhs.b < 1ll * rhs.a * b;
	}
	
	bool operator == (const Frac &rhs) const {
		return 1ll * a * rhs.b == 1ll * rhs.a * b;
	}
};

int m;
Frac v[N];
std::pair<int, int> b[N];

struct BIT {
	int c[N];
	
	void add(int x, int v) {
		for (; x <= n; x += x & -x) {
			c[x] += v;
		}
	}
	
	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n >> W;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].x >> a[i].v;
	}
	
	m = 0;
	for (int i = 1; i <= n; ++i) {
		v[++m] = Frac(a[i].x, a[i].v + W);
	}
	std::sort(v + 1, v + 1 + m);
	m = std::unique(v + 1, v + 1 + m) - v - 1;
	for (int i = 1; i <= n; ++i) {
		b[i].first = std::lower_bound(v + 1, v + 1 + m, Frac(a[i].x, a[i].v + W)) - v;
	}

	m = 0;
	for (int i = 1; i <= n; ++i) {
		v[++m] = Frac(a[i].x, a[i].v - W);
	}
	std::sort(v + 1, v + 1 + m);
	m = std::unique(v + 1, v + 1 + m) - v - 1;
	for (int i = 1; i <= n; ++i) {
		b[i].second = std::lower_bound(v + 1, v + 1 + m, Frac(a[i].x, a[i].v - W)) - v;
		b[i].second = -b[i].second;
	}

	std::sort(b + 1, b + 1 + n);
	long long ans = 0;
	for (int i = n; i; --i) {
		ans += T.query(-b[i].second);
		T.add(-b[i].second, 1);
	}
	std::cout << ans << "\n";
}