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

int k;
ll res[2][N];
vector<pii> g[N];

void dfs(int u, int p) {
	vector<pair<ll,ll> > sons;
	FOR(i,SZ(g[u])) {
		int v = g[u][i].fi, c = g[u][i].se;
		if (v==p) continue;
		dfs(v,u);
		//printf("%d -> %d\n", u, v);
		sons.pb(mp(res[0][v]+c, res[1][v]+c));
	}
	sort(sons.begin(), sons.end());
	reverse(sons.begin(), sons.end());
	int l = SZ(sons);
	ll sumf = 0, tmp = k-1 < l ? sons[k-1].fi : 0;
	FOR(i,min(k-1,l)) sumf += sons[i].fi;
	res[0][u] = sumf;
	FOR(i,l) {
		if (i >= k-1) res[1][u] = max(res[1][u], sumf+sons[i].se);
		else res[1][u] = max(res[1][u], sumf+tmp+sons[i].se-sons[i].fi);
	}
	//printf("dfs %d = %d %d (l=%d)\n", u, res[0][u], res[1][u], l);
}

int main() {
	int n;
	scanf("%d%d", &n, &k);
	FOR(i,n-1) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].pb(mp(b,c));
		g[b].pb(mp(a,c));
	}
	dfs(0, -1);
	cout << res[1][0] << "\n";
	return 0;
}