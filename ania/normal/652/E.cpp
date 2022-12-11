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
#define FOREACH(i,t) for (list<Edge>::iterator i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

#define N 1000007

struct Edge { // PRE: musi by bcc = -1 i bridge = 0 (konstruktor ustawia)
	Edge* rev;
	int dest;
	int bcc; // OUT: Numer komponentu
	bool bridge; // OUT: Czy most
	bool art;
	Edge(int v, int z) : dest(v), bcc(-1)
	, bridge(0)
	{art=z;};
};

int n; // IN: Liczba wierzchokw
list<Edge> adj[N]; // IN: Listy ssiedztwa
int visit[N];

void add_edge (int a, int b, int z) {
	adj[a].pb(Edge(b,z)); adj[b].pb(Edge(a,z));
	adj[a].back().rev = &adj[b].back();
	adj[b].back().rev = &adj[a].back();
}

int dfsTime;

int bccDFS (int v, bool root = 0) {
	int lo = visit[v] = ++dfsTime;
	FOREACH(it,adj[v]) {
		if (it->bcc != -1) continue;
		it->rev->bcc = -2;
		if (!visit[it->dest]) {
			int ulo = bccDFS(it->dest);
			lo = min(ulo, lo);
			it->bridge = it->rev->bridge = (ulo > visit[v]);
		} else lo = min(lo, visit[it->dest]);
	}
	return lo;
}

void computeBCC() {
	fill(visit, visit+n+1, 0);
	dfsTime = 1;
	FORI(i,n) if(!visit[i]) bccDFS(i, 1);
}

int par[N];
int fi(int a) {
	return par[a] == a ? a : par[a] = fi(par[a]);
}
void uni(int a, int b) {
	par[fi(a)] = fi(b);
}

vector<pii> g[N];
int has_art[N];

bool dfs(int u, int dest, int pp, int art) {
	art |= has_art[u];
	if (u==dest) return art;
	FOR(i,SZ(g[u])) if (g[u][i].fi != pp) {
		if (dfs(g[u][i].fi, dest, u, art | g[u][i].se))
			return true;
	}
	return false;
}

int main() {
	int m;
	scanf("%d%d", &n, &m);
	FOR(i,m) {
		int a,b,z;
		scanf("%d%d%d", &a, &b, &z);
		a--; b--;
		add_edge(a,b,z);
	}
	computeBCC();
	FOR(i,n) par[i] = i;
	FOR(i,n) FOREACH(j,adj[i]) if (!j->bridge) uni(i, j->dest);
	FOR(i,n) FOREACH(j,adj[i]) if (!j->bridge && j->art) has_art[fi(i)] = true;
	FOR(i,n) FOREACH(j,adj[i]) if (j->bridge) {
		g[fi(i)].push_back(make_pair(fi(j->dest), j->art));
	}
	/*
	FOR(i,n) {
		printf("%d : ", i);
		FOR(j,SZ(g[i])) printf("(%d, %d) ", g[i][j].fi, g[i][j].se);
		printf("\n");
	}*/
	int A, B;
	scanf("%d%d", &A, &B);
	A--; B--;
	A = fi(A);
	B = fi(B);
	printf("%s\n", dfs(A,B,-1,0) ? "YES" : "NO");
	return 0;
}