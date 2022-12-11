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
const int mod = 1000000007;

int qpow(int a, int n) {
	if (n==0) return 1;
	int b = qpow(a,n/2);
	b=1LL*b*b%mod;
	if (n&1) b=1LL*a*b%mod;
	return b;
}

int inv(int a) {
	return qpow(a,mod-2);
}

vi g[N];
int val[N], cst[N], self[N];
int use[N];

void dfs(int u, int p) {
	FOR(i,SZ(g[u])) {
		int v = g[u][i];
		if (v==p) continue;
		if (!use[v]) continue;
		dfs(v,u);
		int cur = inv(self[v]);
		val[v] = 1LL * val[v] * cur % mod;
		cst[v] = 1LL * cst[v] * cur % mod;
		self[u] = (mod + self[u] - 1LL*val[v]*val[u]%mod) % mod;
		cst[u] = (mod + cst[u] - 1LL*cst[v]*val[u]%mod) % mod;
	}
	//printf("dfs %d = %d %d\n", u, self[u], 4LL*cst[u]%mod);
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n-1) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		cst[a] += c;
		cst[b] += c;
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,n) {
		val[i] = inv(SZ(g[i]));
		cst[i] = 1LL * cst[i] * val[i] % mod;
		self[i] = mod-1;
		if (SZ(g[i]) > 1) use[i] = 1;
		//printf("%d -- %d %d %d %d\n", i, SZ(g[i]), val[i], cst[i], use[i]);
	}
	dfs(0, -1);
	cst[0] = (mod - 1LL * cst[0] * inv(self[0]) % mod) % mod;
	printf("%d\n", cst[0]);
	return 0;
}