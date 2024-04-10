#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int to, c, f, cost;

  Edge(int _to, int _c, int _cost): to(_to), c(_c), f(0), cost(_cost) {}
};

const int MAXN = 105, INF = 1000 * 1000 * 1000 + 5;
int s[MAXN], dist[MAXN], p[MAXN], mincf[MAXN];
char inside[MAXN];
vector<int> g[MAXN];
vector<Edge> e;

void addEdge(int v, int u, int c, int cost) {
  g[v].push_back(e.size());
  e.push_back(Edge(u, c, cost));
  g[u].push_back(e.size());
  e.push_back(Edge(v, 0, -cost));
}

pair<int, int> addFlow(int s, int t, int n) {
  for(int i = 0; i < n; i++) {
    dist[i] = INF;
    p[i] = -1;
    mincf[i] = INF;
    inside[i] = false;
  }
  vector<int> st;
  dist[s] = 0;
  st.push_back(s);
  inside[s] = true;
  for(size_t l = 0; l < st.size(); l++) {
    int v = st[l];
    inside[v] = false;
    for(size_t i = 0; i < g[v].size(); i++) {
      int id = g[v][i], u = e[id].to, cf = e[id].c - e[id].f, w = e[id].cost;
      if(!cf)
        continue;
      if(dist[u] > dist[v] + w) {
        dist[u] = dist[v] + w;
        p[u] = id;
        mincf[u] = min(mincf[v], cf);
        if(!inside[u]) {
          inside[u] = true;
          st.push_back(u);
        }
      }
    }
  }
  if(dist[t] == INF)
    return make_pair(0, 0);
  int flow = mincf[t], price = flow * dist[t];
  for(int v = t; v != s;) {
    int id = p[v];
    e[id].f += flow;
    e[id ^ 1].f -= flow;
    v = e[id ^ 1].to;
  }
  return make_pair(flow, price);
}

int solve(int ss, int tt, int n, int ff) {
  if(ff > 0) {
    addEdge(ss, 0, ff, 0);
    addEdge(n - 1, tt, ff, 0);
  }
  else {
    addEdge(ss, n - 1, -ff, 0);
    addEdge(0, tt, -ff, 0);
  }
  int ans = 0;
  while(true) {
    pair<int, int> f = addFlow(ss, tt, n + 2);
    if(!f.first)
      break;
    ans += f.second;
  }
  e.pop_back();
  e.pop_back();
  e.pop_back();
  e.pop_back();
  g[ss].pop_back();
  g[n - 1].pop_back();
  g[0].pop_back();
  g[tt].pop_back();
  for(size_t i = 0; i < e.size(); i++)
    e[i].f = 0;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for(int i = 0; i < m; i++) {
    int v, u, c, f;
    cin >> v >> u >> c >> f;
    v--;
    u--;
    s[u] += f;
    s[v] -= f;
    if(f <= c) {
      addEdge(u, v, f, 1);
      addEdge(v, u, c - f, 1);
      addEdge(v, u, INF, 2);
    }
    else {
      ans += f - c;
      addEdge(u, v, f - c, 0);
      addEdge(u, v, c, 1);
      addEdge(v, u, INF, 2);
    }
  }
  int ss = n, tt = n + 1;
  for(int i = 0; i < n; i++)
    if(s[i] > 0)
      addEdge(ss, i, s[i], 0);
    else if(s[i] < 0)
      addEdge(i, tt, -s[i], 0);
  int l = -INF, r = INF;
  while(l < r - 5) {
    int m0 = (l + r) / 2, m1 = m0 + 1;
    if(solve(ss, tt, n, m0) < solve(ss, tt, n, m1))
      r = m1;
    else
      l = m0;
  }
  int ans0 = INF;
  for(int i = l; i <= r; i++)
    ans0 = min(ans0, solve(ss, tt, n, i));
  ans += ans0;
  cout << ans << '\n';
  return 0;
}