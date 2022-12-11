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

const int maxn = 1000100;

vi r;
vi g[maxn];

void dfs(int u, int p, int h) {
	FOR(i,SZ(g[u])) {
		int v = g[u][i];
		if (v != p) dfs(v,u,h+1);
	}
	if (SZ(g[u]) == 1) {
		r.push_back(h);
	}
}

int get(int u) {
	dfs(u,0,0);
	sort(r.begin(), r.end());
	int v = 0;
	FOR(i,SZ(r)) {
		if (r[i] > v) v = r[i];
		v++;
	}
	r.clear();
	return v;
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n-1) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int res = 0;
	FOR(i,SZ(g[0])) {
		res = max(res, get(g[0][i]));
	}
	printf("%d\n", res);
	return 0;
}