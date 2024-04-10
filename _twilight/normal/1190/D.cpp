#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 2e5 + 5;

typedef class Point {
	public:
		int x, y;

		Point(int x = 0, int y = 0) : x(x), y(y) {	}

		boolean operator < (Point a) const {
			return (y ^ a.y) ? (y > a.y) : (x < a.x); 	
		}
} Point;

typedef class Fenwick {
	public:
		int n;
		int a[N];

		void init(int n) {
			this->n = n;
			memset(a, 0, sizeof(int) * (n + 1));
		}

		void add(int idx, int val) {
			for ( ; idx <= n; idx += (idx & (-idx)))
				a[idx] += val;
		}
		int query(int idx) {
			int rt = 0;
			for ( ; idx; idx -= (idx & (-idx)))
				rt += a[idx];
			return rt;
		}
		int query(int l, int r) {
			return query(r) - query(l - 1);
		}
} Fenwick;

int n;
Point ps[N];
Fenwick fen;
boolean vis[N];
vector<int> Vx;
int xs[N], ys[N];

ll C2(int x) {
	return (x * 1ll * (x + 1)) >> 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", xs + i, ys + i);
		Vx.push_back(xs[i]);
	}
	sort(Vx.begin(), Vx.end());
	Vx.erase(unique(Vx.begin(), Vx.end()), Vx.end());
	for (int i = 1; i <= n; i++) {
		xs[i] = lower_bound(Vx.begin(), Vx.end(), xs[i]) - Vx.begin() + 1;
		ps[i] = Point(xs[i], ys[i]);
	}
	sort(ps + 1, ps + n + 1);
	ll ans = 0;
	fen.init(n);
	for (int i = 1, j = 1; i <= n; i = j) {
		while (j <= n && ps[j].y == ps[i].y) {
			if (!vis[ps[j].x]) {
				vis[ps[j].x] = true;
				fen.add(ps[j].x, 1);
			}
			j++;
		}
		int ls = 0;
		ll c = C2(fen.query(1, n));
		for (int k = i; k < j; k++) {
			if (ps[k].x > ls + 1) {
				c -= C2(fen.query(ls + 1, ps[k].x - 1));
			}
			ls = ps[k].x;
		}
		if (ls < n)
			c -= C2(fen.query(ls + 1, n));
		ans += c;
	}
	printf("%lld\n", ans);
	return 0;
}