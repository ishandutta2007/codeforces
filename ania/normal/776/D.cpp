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

int n,m,wrong;
int g[N][2], r[N], vis[N], pa[N];
vi G[N];

int fi(int a) {
	return pa[a]==a ? a : pa[a]=fi(pa[a]);
}

void uni(int a, int b) {
	pa[fi(a)]=fi(b);
}

void dfs(int u, int c) {
	vis[u]=c;
	FOR(i,SZ(G[u])) {
		int v=G[u][i];
		if (!vis[v]) dfs(v,3-c);
		if (vis[v] == c) wrong=1;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%d", &r[i]);
	FOR(i,n) g[i][0] = g[i][1] = -1;
	FOR(i,m) pa[i]=i;
	FOR(i,m) {
		int k;
		scanf("%d", &k);
		FOR(j,k) {
			int x;
			scanf("%d", &x);
			x--;
			if (g[x][0]==-1) g[x][0]=i;
			else g[x][1]=i;
		}
	}
	FOR(i,n) if (r[i]==1) uni(g[i][0], g[i][1]);
	FOR(i,n) if (r[i]==0) {
		G[fi(g[i][0])].push_back(fi(g[i][1]));
		G[fi(g[i][1])].push_back(fi(g[i][0]));
	}
	FOR(i,m) fi(i);
	FOR(i,m) if (!vis[fi(i)]) dfs(fi(i),1);
	printf("%s\n", wrong ? "NO" : "YES");
	return 0;
}