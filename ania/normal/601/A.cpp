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

const int inf = 1000000009;
const int maxn = 404;

int dist[maxn];
vi g[maxn], h[maxn];

int main() {
	int n,m;
	bool fnd=false;
	scanf("%d%d", &n, &m);
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		if (a==0 && b==n-1) fnd=true;
		if (a==n-1 && b==0) fnd=true;
	}
	if (fnd) {
		FOR(i,n) {
			set<int> s;
			FOR(j,n) s.insert(j);
			FOR(j,SZ(g[i])) s.erase(g[i][j]);
			for(set<int>::iterator j=s.begin(); j!=s.end(); j++) h[i].pb(*j);
		}
	} else {
		FOR(i,n) h[i]=g[i];
	}
	FOR(i,n) dist[i]=inf;
	dist[0]=0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		FOR(i,SZ(h[u])) {
			int v = h[u][i];
			if (dist[v] != inf) continue;
			dist[v] = dist[u]+1;
			q.push(v);
			if (v==n-1) {
				printf("%d\n", dist[v]);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}