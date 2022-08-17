#include <iostream>
#include <queue>
#include <vector>

#define int long long

const int MAXN = 505;

int a[MAXN][MAXN];
int ap[MAXN][MAXN];

using namespace std;

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;
vector<Edge> edges;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
  d.assign(n, INF);
  d[v0] = 0;
  vector<bool> inq(n, false);
  queue<int> q;
  q.push(v0);
  p.assign(n, -1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = false;
    for (int v : adj[u]) {
      if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
        d[v] = d[u] + cost[u][v];
        p[v] = u;
        if (!inq[v]) {
          inq[v] = true;
          q.push(v);
        }
      }
    }
  }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
  adj.assign(N, vector<int>());
  cost.assign(N, vector<int>(N, 0));
  capacity.assign(N, vector<int>(N, 0));
  for (Edge e : edges) {
    adj[e.from].push_back(e.to);
    adj[e.to].push_back(e.from);
    cost[e.from][e.to] = e.cost;
    cost[e.to][e.from] = -e.cost;
    capacity[e.from][e.to] = e.capacity;
  }

  int flow = 0;
  int cost = 0;
  vector<int> d, p;
  while (flow < K) {
    shortest_paths(N, s, d, p);
    if (d[t] == INF)
      break;

    // find max flow on that path
    int f = K - flow;
    int cur = t;
    while (cur != s) {
      f = min(f, capacity[p[cur]][cur]);
      cur = p[cur];
    }

    // apply flow
    flow += f;
    cost += f * d[t];
    cur = t;
    while (cur != s) {
      capacity[p[cur]][cur] -= f;
      capacity[cur][p[cur]] += f;
      cur = p[cur];
    }
  }

  if (flow < K)
    return -1;
  else
    return cost;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = n-1; i >= 0; i--) {
    for(int j = m-1; j >= 0; j--) {
      char c;
      std::cin >> c;
      a[i][j] = c == 'B';
    }
  }

  int cur = 0;
  int min = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(j)
        a[i][j] ^= ap[i][j-1];
      if(i)
        a[i][j] ^= ap[i-1][j];
      if(i && j)
        a[i][j] ^= ap[i-1][j-1];
      ap[i][j] = a[i][j];
      if(j)
        ap[i][j] ^= ap[i][j-1];
      if(i)
        ap[i][j] ^= ap[i-1][j];
      if(i && j)
        ap[i][j] ^= ap[i-1][j-1];
      cur += a[i][j];
    }
  }

  /*
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      std::cout << ch[i][j] << " ";
    }
  std::cout << std::endl;
  }
  */

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      a[i][j] = (a[i][j] ? -1 : 1);
    }
  }

  int N = n-1 + m-1 + 2;
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
      int next = a[0][j] + a[i][0] + a[i][j] + 2;
      edges.push_back({i-1, n+j-2, 1, next});
    }
    edges.push_back({n+m-2, i-1, 1, 0});
  }
  for(int j = 1; j < m; j++)
    edges.push_back({n+j-2, n+m-1, 1, 0});
  edges.push_back({n+m-2, n+m-1, N, 0});

  int minc = min_cost_flow(N, edges, N, n+m-2, n+m-1);
  int flow = capacity[n+m-2][n+m-1];

  int best = cur;
  best = std::min(best, best+minc+(flow%2 ? a[0][0] : 0));
  std::cout << best << std::endl;

  return 0;
}