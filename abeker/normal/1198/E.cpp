#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

namespace Dinic {
	#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
	#define REP(i, n) FOR(i, 0, n)

	typedef long long llint;
	
  const int MAXV = 310;
  const int MAXE = 300000;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], dist[MAXV], curr[MAXV];
  int next[MAXE], adj[MAXE]; llint cap[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void edge(int x, int y, llint c1, llint c2) {
    adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
  }

  llint push(int x, int sink, llint flow) {
    if (x == sink) return flow;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && dist[x] + 1 == dist[y])
        if (llint f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  llint run(int src, int sink) {
    llint ret = 0;
    for (;;) {
      REP(i, V) curr[i] = last[i];
      REP(i, V) dist[i] = -1;

      queue<int> Q;
      Q.push(src), dist[src] = 0;

      while (!Q.empty()) {
        int x = Q.front(); Q.pop();

        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
        }
      }
      if (dist[sink] == -1) break;

      while (llint f = push(src, sink, oo)) ret += f;
    }
    return ret;
  }
}

int N, M;
vector <int> X, Y;
int x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		X.push_back(x1[i]);
		X.push_back(x2[i] + 1);
		Y.push_back(y1[i]);
		Y.push_back(y2[i] + 1);		
	}
}

int solve() {
	Dinic::init(MAXN + 1);
	
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	
	for (int i = 1; i < X.size(); i++)
		Dinic::edge(0, i, X[i] - X[i - 1], 0);
	
	for (int i = 1; i < Y.size(); i++)
		Dinic::edge(i + X.size(), MAXN, Y[i] - Y[i - 1], 0);
	
	for (int i = 1; i < X.size(); i++)
		for (int j = 1; j < Y.size(); j++)
			for (int k = 0; k < M; k++)
				if (x1[k] <= X[i - 1] && X[i] - 1 <= x2[k] && y1[k] <= Y[j - 1] && Y[j] - 1 <= y2[k])
					Dinic::edge(i, j + X.size(), 2e9, 0);
					
	return Dinic::run(0, MAXN);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}