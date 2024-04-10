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
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
int n, x[N], y[N], X[N], Y[N], A, B, C, D;
bool cmp1(int u, int v) {return (ll) (y[u] - y[v]) * B > (ll) A * (x[u] - x[v]);}
bool cmp2(int u, int v) {return (ll) (y[u] - y[v]) * D < (ll) C * (x[u] - x[v]);}
bool equ1(int u, int v) {return (ll) (y[u] - y[v]) * B == (ll) A * (x[u] - x[v]);}
bool equ2(int u, int v) {return (ll) (y[u] - y[v]) * D == (ll) C * (x[u] - x[v]);}
int m, a[N], d[N], f[N];
void modify(int p, int v) {for(; p <= m; p += lowbit(p)) d[p] = max(d[p], v);}
int query(int p) {int res = 0; for(; p; p -= lowbit(p)) res = max(res, d[p]); return res;}
void solve() {
	m = *max_element(a + 1, a + n + 1);
	rep(i, 1, n) {
		f[i] = query(a[i] - 1) + 1;
		modify(a[i], f[i]);
	}
	printf("%d\n", f[n] - 1);
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d/%d%d/%d", &n, &A, &B, &C, &D);
	rep(i, 1, n) scanf("%d%d", &x[i], &y[i]);
	VI p, q;
	x[n + 1] = y[n + 1] = 0; n++;
	rep(i, 1, n) p.pb(i), q.pb(i);
	sort(all(p), cmp1); sort(all(q), cmp2);
	p.erase(unique(all(p), equ1), p.end());
	q.erase(unique(all(q), equ2), q.end());
	vector<pii> vec;
	rep(i, 1, n) {
		X[i] = lower_bound(all(p), i, cmp1) - p.begin() + 1;
		Y[i] = lower_bound(all(q), i, cmp2) - q.begin() + 1;
		vec.emplace_back(X[i], Y[i]);
	}
	sort(all(vec), [&](pii u, pii v) {
		return u.fi != v.fi ? u.fi < v.fi : u.se > v.se;
	});
	rep(i, 1, n) if (vec[i - 1] == mp(X[n], Y[n])) {
		n = i;
		break;
	}
	rep(i, 1, n) a[i] = vec[i - 1].se;
	solve();
	return 0;
}