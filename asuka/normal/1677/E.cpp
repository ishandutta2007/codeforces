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
const int N = 200015, M = 1000015;

int n, Q, p[N], q[N], Min[N], Max[N];
vector<int> vl[N], vr[N];

struct fenwick {
	ll t1[N], t2[N];

	void add(int k, int v) {
		ll v1 = k * v;

		while (k <= n) {
			t1[k] += v, t2[k] += v1;
			k += lowbit(k);
		}
	}

	ll getsum(ll *t, int k) {
		ll ret = 0;

		while (k) {
			ret += t[k];
			k -= lowbit(k);
		}

		return ret;
	}

	void add1(int l, int r, int v) {
		add(l, v), add(r + 1, -v);
	}

	ll getsum1(int l, int r) {
		return (r + 1ll) * getsum(t1, r) - 1ll * l * getsum(t1, l - 1) -
		       (getsum(t2, r) - getsum(t2, l - 1));
	}
} ;

struct solver {
	vector<pii> add[N];
	vector<tuple<int, int, int>> qry[N];
	ll ans[M];
	fenwick T;

	void addline(int x, int l, int r) {
		add[x].emplace_back(l, r);
	}

	void addqry(int xl, int xr, int l, int r, int id) {
		qry[xl - 1].emplace_back(l, r, -id);
		qry[xr].emplace_back(l, r, id);
	}

	void gao() {
		rep(i, 1, n) {
			for (auto [l, r] : add[i]) {
				T.add1(l, r, 1);
			}

			for (auto [l, r, id] : qry[i]) {
				if (id > 0) ans[id] += T.getsum1(l, r);
				else ans[-id] -= T.getsum1(l, r);
			}
		}
	}
} L, R;

void solve(int u, int l, int r) {
	if (l == r) {
		return;
	}


	int mid = (l + r) >> 1;

	{
		// max[i, mid] >= max[mid + 1, j]
		int ptr = mid, mx = 0;

		per(i, l, r) {
			for (int o : vl[i])
				Min[p[i] * p[o]] = min(Min[p[i] * p[o]], o);

			if (i <= mid) {
				mx = max(mx, p[i]);

				while (ptr + 1 <= r && p[ptr + 1] <= mx) ptr++;



				if (max(mid + 1, Min[mx]) <= ptr) {
					L.addline(i, max(mid + 1, Min[mx]), ptr);
				}
			}
		}

		rep(i, l, r) {
			for (int o : vl[i])
				Min[p[i] * p[o]] = inf;
		}

	}

	{
		// max[i, mid] < max[mid + 1, j]
		int ptr = mid + 1, mx = 0;

		rep(j, l, r) {
			for (int o : vr[j])
				Max[p[j] * p[o]] = max(Max[p[j] * p[o]], o);

			if (j > mid) {

				mx = max(mx, p[j]);

				while (l <= ptr - 1 && p[ptr - 1] < mx) ptr--;



				if (ptr <= min(mid, Max[mx])) {
					R.addline(j, ptr, min(mid, Max[mx]));
				}
			}

		}

		rep(j, l, r) {
			for (int o : vr[j])
				Max[p[j] * p[o]] = 0;
		}
	}

	solve(u << 1, l, mid); solve(u << 1 | 1, mid + 1, r);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &Q);

	rep(i, 1, n) scanf("%d", &p[i]), q[p[i]] = i;

	rep(i, 1, n) {
		for (int j = 1; j * i <= n; ++j) {
			int l = q[i], r = q[j];

			if (l == r) continue;

			if (l > r) swap(l, r);

			vl[l].pb(r); vr[r].pb(l);
		}
	}

	fill(Min, Min + n + 1, inf);
	solve(1, 1, n);

	rep(i, 1, Q) {
		int x, y; scanf("%d%d", &x, &y);
		L.addqry(x, y, x, y, i);
		R.addqry(x, y, x, y, i);
	}

	L.gao(); R.gao();

	rep(i, 1, Q) printf("%lld\n", L.ans[i] + R.ans[i]);
	return 0;
}