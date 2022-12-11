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

const int N = 100100;

int res[N];
vector<pii> g[N];

void dfs(int u, int p) {
	FOR(i,SZ(g[u])) {
		int v = g[u][i].fi, c = g[u][i].se;
		if (v==p) continue;
		dfs(v,u);
		res[u] = max(res[u], c + res[v]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	dfs(0, -1);
	printf("%d\n", res[0]);
	return 0;
}