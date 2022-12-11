#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 100100;

vi g[maxn];
int a[maxn], b[maxn], c[maxn], num[maxn], par[maxn], S[maxn];
long long val[maxn];

void dfs (int u, int pp) {
	par[u]=pp;
	S[u] = 1;
	FOR(i,SZ(g[u])) {
		int v=g[u][i];
		if (v==pp) continue;
		dfs(v,u);
		S[u] += S[v];
	}
}

int main() {
	int n,q;
	long long res=0;
	scanf("%d", &n);
	FOR(i,n-1) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		a[i]--; b[i]--;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	dfs(0,-1);
	FOR(i,n-1) {
		if (par[a[i]] == b[i]) swap(a[i],b[i]);
		num[i]=S[b[i]];
		val[i] = 1LL*num[i]*(n-num[i]);
		res += val[i] * c[i];
	}
	scanf("%d", &q);
	FOR(_,q) {
		int id,C;
		scanf("%d%d", &id, &C);
		id--;
		res -= val[id] * c[id];
		c[id]=C;
		res += val[id] * c[id];
		printf("%.7lf\n", 6.0*res/n/(n-1));
	}
	return 0;
}