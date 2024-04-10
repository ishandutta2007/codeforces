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

vi g[N];
int vis[N], c[N], si[N];

void dfs(int u, int cc) {
	vis[u] = cc;
	si[cc-1]++;
	FOR(i,SZ(g[u])) {
		int v = g[u][i];
		if (vis[v]) continue;
		dfs(v, cc);
	}
}

void test() {
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,k) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i,k) dfs(c[i], i+1);
	int mxs = 0;
	FOR(i,k) mxs = max(mxs, si[i]);
	long long can = 0;
	FOR(i,k) can += 1LL * si[i] * (si[i]-1) / 2;
	int solo=0;
	FOR(i,n) if (vis[i]==0) solo++;
	can += 1LL * solo * (solo-1) / 2;
	can += 1LL * solo * mxs;
	cout << can - m << "\n";
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}