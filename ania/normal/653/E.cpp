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

const int maxn = 300300;

int n,m,k,cnt;
set<int> nvis, g[maxn];
bool vis[maxn];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (set<int> :: iterator it = nvis.begin(); it != nvis.end(); ) {
			if (g[v].find(*it) == g[v].end()) {
				q.push(*it);
				set<int> :: iterator tmp = it;
				it++;
				nvis.erase(tmp);
			} else {
				it++;
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
		if (a==0 || b==0) cnt++;
	}
	if (cnt+k > n-1) {
		printf("impossible\n");
		return 0;
	}
	/*
	FOR(i,n) {
		printf("%d : ", i);
		for (x:g[i]) printf("%d ", x);
		printf("\n");
	}
	*/
	FORI(i,n-1) nvis.insert(i);
	bfs(0);
	if (nvis.size()) {
		printf("impossible\n");
		return 0;
	}
	FOR(i,n) vis[i] = false;
	g[0].clear();
	FOR(i,n) g[i].erase(0);
	cnt = 0;
	FORI(i,n-1) nvis.insert(i);
	while (!nvis.empty()) {
		int x = *nvis.begin();
		nvis.erase(x);
		cnt++;
		bfs(x);
	}
	if (cnt > k) {
		printf("impossible\n");
		return 0;
	}
	printf("possible\n");
	return 0;
}