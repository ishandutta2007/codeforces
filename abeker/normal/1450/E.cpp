#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e2 + 5;
const int INF = 1e9;

class Edge {
  int a, b, c;
public:
  Edge(int a, int b, int c) : a(a), b(b), c(c) {}
  Edge() : a(0), b(0), c(0) {}
  void relaxEdge(vector <int> &d) const {
    d[b] = min(d[b], d[a] + c);
  }
  bool checkEdge(vector <int> &d) const {
    return d[b] <= d[a] + c;
  }
};

int N, M;
vector <int> ans;
vector <int> adj[MAXN];
vector <Edge> edges;
int clr[MAXN];
int maks = -1;

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int x, y, e;
    scanf("%d%d%d", &x, &y, &e);
    adj[x].push_back(y);
    adj[y].push_back(x);
    edges.push_back(Edge(x, y, 1));
    edges.push_back(Edge(y, x, 1 - 2 * e)); 
  }
}

void bye() {
  puts("NO");
  exit(0);
}

bool dfs(int x, int c) {
  if (clr[x] != -1)
    return clr[x] == c;
  clr[x] = c;
  for (auto it : adj[x])
    if (!dfs(it, c ^ 1))
      return false;
  return true;
}

bool bipartite() {
  memset(clr, -1, sizeof clr);
  return dfs(1, 0);
}

void bellman_ford(int src) {
  vector <int> dist(N + 1, INF);
  dist[src] = 0;
  for (int i = 1; i < N; i++)
    for (auto it : edges)
      it.relaxEdge(dist);
  for (auto it : edges)
    if (!it.checkEdge(dist))
      return;
  for (int i = 1; i <= N; i++)
    if (dist[i] < 0)
      return;
  int curr = *max_element(dist.begin() + 1, dist.begin() + N + 1);
  if (curr > maks) {
    maks = curr;
    ans = dist;
  }
}

void solve() {
  if (!bipartite()) 
    bye();
  for (int i = 1; i <= N; i++)
    bellman_ford(i);
  if (maks == -1)
    bye();
  printf("YES\n%d\n", maks);
  for (int i = 1; i <= N; i++)
    printf("%d ", ans[i]);
  puts("");
}

int main() {
  load();
  solve();
  return 0;
}