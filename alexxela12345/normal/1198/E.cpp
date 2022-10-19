#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;


template<int SZ>
struct MaxFlow {
  struct Edge {
    int to, rev;
    ll cap, flow;

    Edge(int to, int rev, ll cap, ll flow) : to(to), rev(rev), cap(cap), flow(flow) {};
  };
  
  vector<Edge> g[SZ];

  void addEdge(int u, int v, ll cap) {
    Edge a(v, (int) g[v].size(), cap, 0LL);
    Edge b(u, (int) g[u].size(), 0LL, 0LL);
    g[u].push_back(a);
    g[v].push_back(b);
  }

  int ST, EN, level[SZ], ind[SZ];

  bool bfs() {
    for (int i = 0; i < SZ; i++) {
      level[i] = -1;
      ind[i] = 0;
    }
    level[ST] = 0;
    queue<int> q;
    q.push(ST);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (Edge e : g[u]) {
        if (level[e.to] == -1 && e.flow < e.cap) {
          q.push(e.to);
          level[e.to] = level[u] + 1;
        }
      }
    }
    return level[EN] >= 0;
  }
  
  ll dfs(int v, ll flow) {
    if (v == EN) {
      return flow;
    }
    for (; ind[v] < g[v].size(); ind[v]++) {
      Edge &e = g[v][ind[v]];
      if (level[e.to] != level[v] + 1 || e.cap == e.flow) {
        continue;
      }
      ll new_f = dfs(e.to, min(flow, e.cap - e.flow));
      if (new_f) {
        e.flow += new_f;
        g[e.to][e.rev].flow -= new_f;
        return new_f;
      }
    }
    return 0;
  }

  ll maxFlow(int st, int en) {
    ST = st;
    EN = en;
    ll ans = 0;
    while (bfs()) {
      ll flow = dfs(ST, LLONG_MAX);
      while (flow) {
        ans += flow;
        flow = dfs(ST, LLONG_MAX);
      }
    }
    return ans;
  }
};

bool b[100][100];

int main() {
  int n, m;
  cin >> n >> m;
  MaxFlow<210> mf;
  vector<pair<pair<int, int>, pair<int, int>>> arr;
  map<int, int> xs, ys;
  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    arr.emplace_back((pair<pair<int, int>, pair<int, int>>){{x1, y1}, {x2, y2}}); 
    xs[x1] = 0;
    xs[x2 + 1] = 0;
    ys[y1] = 0;
    ys[y2 + 1] = 0;
  }
  int cur_num = 0;
  for (pair<const int, int> &el : xs) {
    el.second = cur_num++;
  }
  cur_num = 0;
  for (pair<const int, int> &el : ys) {
    el.second = cur_num++;
  }
  for (int i = 0; i < m; i++) {
    int x1 = arr[i].first.first;
    int y1 = arr[i].first.second;
    int x2 = arr[i].second.first;
    int y2 = arr[i].second.second;
    x1 = xs[x1];
    x2 = xs[x2 + 1] - 1;
    y1 = ys[y1];
    y2 = ys[y2 + 1] - 1;
    for (int j = x1; j <= x2; j++) {
      for (int k = y1; k <= y2; k++) {
        b[j][k] = 1;        
      }
    }
  }
  vector<pair<int, int>> xx(xs.begin(), xs.end()), yy(ys.begin(), ys.end());
  for (int i = 0; i < (int) xx.size() - 1; i++) {
    mf.addEdge(0, 2 + i, xx[i + 1].first - xx[i].first);
  }
  for (int i = 0; i < (int) yy.size() - 1; i++) {
    mf.addEdge(102 + i, 1, yy[i + 1].first - yy[i].first);
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (b[i][j]) {
        mf.addEdge(2 + i, 102 + j, INF);
      }
    }
  }
  cout << mf.maxFlow(0, 1) << endl;
}