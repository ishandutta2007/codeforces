#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 15015;

int n, a[N], f[N], g[N], ff[N], gg[N];

struct fenwick {
	function<int(int, int)> f;
	int INI, D[N];
	void init() {fill(D, D + n + 1, INI);}
	void upd(int p, int v) {
		if (p < 1 || p > n) return;
		for (; p <= n; p += lowbit(p)) D[p] = f(D[p], v);
	}
	int query(int p) {
		int res = INI;
		for (; p; p -= lowbit(p)) res = f(res, D[p]);
		return res;
	}
} A, B;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		A.f = [](int u, int v) {return max(u, v);};
		A.INI = 0;
		B.f = [](int u, int v) {return min(u, v);};
		B.INI = n + 1;
		int ans = 1;
		rep(_, 1, 2) {
			fill(f, f + n + 1, n + 1);
			fill(g, g + n + 1, 0);
			rep(i, _ == 1 ? n : 1, n - (_ == 2)) f[i] = g[i] = a[i];
			for (int k = _; ; ++k) {
				B.init();
				fill(ff, ff + n + 1, n + 1);
				fill(gg, gg + n + 1, 0);
				per(i, 1, n) {
					if (i + 1 <= n) B.upd(n - a[i + 1] + 1, f[i + 1]);
					ff[i] = min(ff[i], B.query(n - a[i]));
				}
				A.init();
				per(i, 1, n) {
					if (i + k <= n) A.upd(f[i + k], a[i + k]);
					gg[i] = max(gg[i], A.query(a[i] - 1));
				}
				A.init();
				per(i, 1, n) {
					if (i + 1 <= n) A.upd(a[i + 1], g[i + 1]);
					gg[i] = max(gg[i], A.query(a[i] - 1));
				}
				B.init();
				per(i, 1, n) {
					if (i + k <= n) B.upd(n - g[i + k] + 1, a[i + k]);
					ff[i] = min(ff[i], B.query(n - a[i]));
				}
				swap(f, ff); swap(g, gg);
				bool flag = 1;
				rep(i, 1, n) flag &= f[i] > n && g[i] < 1;
				if (flag) {
					ans = max(ans, k - _ + 1);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}