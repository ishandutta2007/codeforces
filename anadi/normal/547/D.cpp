#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define FOR(i,n) REP(i,0,int(n)-1)

const int N = 2e5 + 7;
const int M = 6 * N;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int cnt[2][N];

struct Dinic{
	typedef int T;

	int nodes, src, dest, nedge;
	int point[M], nxt[M], flow[M], capa[M];
	int head[M], dist[M], Q[M], work[M];

	void init (int _nodes, int _src, int _dest) {
	   nodes = _nodes + 2; // na wszelki wypadek
	   src = _src;
	   dest = _dest;
	   FOR(i,nodes) head[i] = -1;
	   nedge = 0;
	}
	void addEdge(int u, int v, int c1, int c2 = 0) {
	   point[nedge]=v, capa[nedge]=c1, flow[nedge]=0,
		     nxt[nedge]=head[u], head[u]=(nedge++);
	   point[nedge]=u, capa[nedge]=c2, flow[nedge]=0,
		     nxt[nedge]=head[v], head[v]=(nedge++);
	}

	bool dinicBfs() {
	   FOR(i,nodes) dist[i] = -1;
	   dist[src] = 0;
	   int szQ = 1;
	   Q[0] = src;
	   FOR(cl,szQ) {
		  for (int k = Q[cl], i = head[k]; i >= 0; i = nxt[i]) {
		     if (flow[i] < capa[i] && dist[point[i]] < 0) {
		        dist[point[i]] = dist[k] + 1;
		        Q[szQ++] = point[i];
		     }
		  }
	   }
	   return dist[dest] >= 0;
	}

	T dinicDfs (int x, T exp) {
	   if (x == dest) return exp;
	   T res = 0;
	   for (int& i = work[x]; i >= 0; i = nxt[i]) {
		  int v = point[i]; T tmp;
		  if (flow[i] < capa[i] && dist[x]+1 == dist[v]
		      && (tmp = dinicDfs(v, min(exp, (T)capa[i] - flow[i]))) > 0) {
		     flow[i] += tmp;
		     flow[i^1] -= tmp;
		     res += tmp;
		     exp -= tmp;
		     if (0 == exp) break;
		  }
	   }
	   return res;
	}

	T dinicFlow () {
	   T res = 0;
	   while (dinicBfs()) {
		  FOR(i,nodes) work[i] = head[i];
		  res += dinicDfs(src,INF);
	   }
	   return res;
	}
} Dinic;

int main(){
	scanf("%d", &n);
	Dinic.init(2 * N + 1, 0, N + N);

	for(int i = 1; i <= n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);

		cnt[0][x]++;
		cnt[1][y]++;
		Dinic.addEdge(x, N + y, 1);
	}

	for(int i = 1; i < N; ++i){
		if(cnt[0][i] > 0)
			Dinic.addEdge(0, i, cnt[0][i] / 2);
		
		if(cnt[1][i] > 0)
			Dinic.addEdge(N + i, N + N, cnt[1][i] / 2);
	}
	
	int edge = n + n;
	Dinic.dinicFlow();

	for(int i = 1; i < N; ++i){
		if(cnt[0][i] & 1)
			Dinic.capa[edge] += 1;
		if(cnt[0][i] > 0)
			edge += 2;
		
		if(cnt[1][i] & 1)
			Dinic.capa[edge] += 1;
		if(cnt[1][i] > 0)
			edge += 2;
	}
	
	Dinic.dinicFlow();
	for(int i = 0; i < n; ++i)
		printf("%c", Dinic.capa[i + i] == Dinic.flow[i + i] ? 'b' : 'r');
	return 0;
}