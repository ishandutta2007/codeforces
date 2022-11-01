#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[605][605];
const int inf = 1e9;
int V, E, N, K;



typedef int LL;

struct Edge {
  int u, v;
  int cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, int cap) {
  	// cout << u << " " << v << " " << cap << endl;
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

// BEGIN CUT
// The following code solves SPOJ problem #4110: Fast Maximum Flow (FASTFLOW)

int cnt[1000];

bool good(int T) {
	int src = 1;
	int des = 2 * V + 2;
	Dinic F (des + 2);
	for(int i = 1; i <= V; i++) {
		F.AddEdge(src, 2 * i, cnt[i]);
	}
	for(int i = 1; i <= V; i++) {
		for(int j = 1; j <= V; j++) {
			if(a[i][j] <= T) {
				int p = 2 * i;
				int q = 2 * j + 1;
				F.AddEdge(p, q, 1);
				// cout << i << " " << j << endl;
			}
		}
	}
	for(int i = 1; i <= V; i++) {
		F.AddEdge(2 * i + 1, des, 1);
	}
	int ans = F.MaxFlow(src, des);
	return ans >= K;
}

int search(int b, int e) {
	if(b == e) {
		return good(b) ? b : -1;
	}
	int m = (b + e) >> 1;
	if(good(m)) return search(b, m);
	else return search(m + 1, e);
}

int main() {
	scanf("%d %d %d %d", &V, &E, &N, &K);
	
	for(int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		cnt[x] += 1;
	}
	
	for(int i = 0; i <= V; i++) {
		for(int j = 0; j <= V; j++) {
			a[i][j] = inf;
		}
	}
	for(int i = 0; i <= V; i++) {
		a[i][i] = 0;
	}
	for(int i = 1; i <= E; i++) {
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		a[p][q] = min(a[p][q], r);
		a[q][p] = min(a[q][p], r);
	}
	for(int k = 1; k <= V; k++) {
		for(int i = 1; i <= V; i++) {
			for(int j = 1; j <= V; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	} 
	printf("%d\n", search(0, 1731311));
	return 0;
}