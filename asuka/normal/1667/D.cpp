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

const int N = 200015;

int n;
vector<int> e[N];
bool f[N][2];

void dfs(int u, int pa) {
	if (pa) e[u].erase(find(all(e[u]), pa));

	f[u][0] = f[u][1] = 0;
	int s = SZ(e[u]), t = s & 1, l = 0, r = 0, fl = 1;

	for (int v : e[u]) {
		dfs(v, u);
		fl &= f[v][0] | f[v][1];

		if (f[v][0]) r++;
		else r--;

		if (f[v][1]) l--;
		else l++;
	}

	if (!fl) return;

	rep(p, 0, pa > 0) {
		int o = t + p * (t ? -2 : 2);
		f[u][t ^ p] = l <= o && o <= r;
	}

}

vector<pii> ans;

void Out(int u, int p, int pa) {
	int s = SZ(e[u]), t = s & 1;
	p ^= t;
	vector<int> vec[3];

	for (int v : e[u]) {
		if (f[v][0] && f[v][1]) vec[2].pb(v);
		else vec[f[v][1]].pb(v);
	}

	auto push = [&](int o) {
		int v;

		if (SZ(vec[o]) > 0) v = vec[o].back(), vec[o].pop_back();
		else v = vec[2].back(), vec[2].pop_back();

		Out(v, o, u);
	};

	if (p == 0 || !pa) {
		if (pa) ans.emplace_back(u, pa);

		rep(i, 1, s) push(t ^ (i & 1));

	} else {
		push(t);

		if (pa) ans.emplace_back(u, pa);

		rep(i, 1, s - 1) push(t ^ (i & 1) ^ 1);
	}
}

void solve() {
	scanf("%d", &n);

	rep(i, 1, n) e[i].clear();

	rep(i, 2, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}

	dfs(1, 0);

	if (!f[1][0] && !f[1][1]) return puts("NO"), void();

	puts("YES");
	ans.clear();
	Out(1, f[1][1], 0);

	for (auto [u, v] : ans) printf("%d %d\n", u, v);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int T;

	for (scanf("%d", &T); T; T--) solve();

	return 0;
}