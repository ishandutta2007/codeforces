#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 300015;
int n, q, k, a[N], b[N], p[N], c[N][2], s[N], mx[N], mn[N];
bool pr[N], sf[N];

void dfs(int u, int pa) {
	if (a[u]) mx[u] = mn[u] = a[u];
	else mx[u] = 1, mn[u] = 1e6;
	if (pa) mn[u] = min(mn[u], mn[pa]);

	rep(o, 0, 1) if (c[u][o]) {
		dfs(c[u][o], u);
		mx[u] = max(mx[u], mx[c[u][o]]);
	}
}

void solve() {
	scanf("%d%d", &n, &q), k = 0;
	rep(i, 1, n) scanf("%d", &p[i]);
	rep(i, 1, n) scanf("%d", &a[i]), k += !a[i];
	rep(i, 1, k - 1) scanf("%d", &b[i]);
	sort(b + 1, b + k);
	int tp = 0;

	rep(i, 1, n) {
		c[i][0] = c[i][1] = 0;
		while (tp && p[s[tp]] < p[i])
			c[i][0] = s[tp--];
		if (tp) c[s[tp]][1] = i;
		s[++tp] = i;
	}

	bool bad = 0;
	dfs(s[1], 0);
	rep(i, 1, n) if (a[i] && mx[i] > a[i]) bad = 1;
	vector<pii> vec;
	vec.reserve(k);
	rep(i, 1, n) if (!a[i]) vec.eb(mx[i], mn[i]);
	sort(all(vec));

	auto solve = [&](vector<int> num) {
		sort(all(num));
		vector<int> rem;
		priority_queue<pii, vector<pii>, greater<pii>> Q;
		int ptr = 0;

		for (int x : num) {
			while (ptr < k && vec[ptr].fi <= x) {
				Q.push(mp(vec[ptr].se, ptr));
				ptr++;
			}

			while (!Q.empty() && Q.top().fi < x) {
				rem.pb(Q.top().se);
				Q.pop();
			}

			if (Q.empty()) {
				rem.clear();
				rem.pb(-1);
				rem.pb(-1);
				return rem;
			}

			int o = Q.top().se;
			Q.pop();
		}

		rep(i, ptr, k - 1) rem.pb(i);
		while (!Q.empty()) rem.pb(Q.top().se), Q.pop();
		return rem;
	};

	auto ini = vector<int>(b + 1, b + k);
	auto rem = solve(ini);
	int lb = 1e6 + 1, rb = 0;

	if (SZ(rem) == 1) {
		int l0 = vec[rem[0]].fi, r0 = vec[rem[0]].se;

		{
			int l = 1, r = l0;

			while (l <= r) {
				int md = (l + r) >> 1;
				ini.pb(md);
				if (solve(ini).empty()) lb = md, r = md - 1;
				else l = md + 1;
				ini.pop_back();
			}
		}

		{
			int l = r0, r = 1e6;

			while (l <= r) {
				int md = (l + r) >> 1;
				ini.pb(md);
				if (solve(ini).empty()) rb = md, l = md + 1;
				else r = md - 1;
				ini.pop_back();
			}
		}
	}

	while (q--) {
		int x;
		scanf("%d", &x);
		puts((!bad && lb <= x && x <= rb) ? "YES" : "NO");
	}
}

int main() {
#ifdef Asuka
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}