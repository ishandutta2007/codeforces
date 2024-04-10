#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const int N = 300300;

int n,m;
vector<pii> g[N];
int vis[N], d[N], si[N];
vi res;

void dfs(int u, int edgn) {
	//printf("visiting %d from %d\n", u+1, edgn); fflush(stdout);
	vis[u] = 1;
	si[u] = d[u];
	FOR(i,SZ(g[u])) {
		int v = g[u][i].fi;
		if (!vis[v]) {
			dfs(v, g[u][i].se);
			si[u] += si[v];
		}
	}
	//printf("visiting %d from %d; si[u] = %d\n", u+1, edgn, si[u]); fflush(stdout);
	if (si[u] % 2 == 1) res.pb(edgn);
}

int main() {
	scanf("%d%d", &n, &m);
	bool ok = true, okm = false;
	FOR(i,n) {
		scanf("%d", &d[i]);
		if (d[i] == -1) okm=true;
		if (d[i] == 1) ok = !ok;
	}
	if (!ok && !okm) {
		printf("-1\n");
		return 0;
	}
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(mp(b, i+1));
		g[b].pb(mp(a, i+1));
	}
	if (!ok) {
		FOR(i,n) if (d[i] == -1) {
			d[i] = 1;
			break;
		}
	}
	FOR(i,n) if (d[i] == -1) d[i] = 0;
	dfs(0, -1);
	sort(res.begin(), res.end());
	printf("%d\n", SZ(res));
	FOR(i,SZ(res)) printf("%d\n", res[i]);
	return 0;
}