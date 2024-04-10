#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>//
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int a[200][200];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int vs = 0;

int id[200][200];

const int N = 4e5 + 10;

struct edge {
  int a, b, cap, flow;
};

vector <int> g[N], gr[N];
vector <int> real_g[N];
int l_cost[200][200], r_cost[200][200];
int a_id[N], b_id[N];

vector <edge> e;

void add_edge(int a, int b, int cap) {
  g[a].push_back(e.size());
  e.push_back({a, b, cap, 0});
  g[b].push_back(e.size());
  e.push_back({b, a, 0, 0});
}

void add_bipartite_edge(int a, int b, int cap) {
  g[a].push_back(e.size());
  e.push_back({a, b, cap, 0});
  g[b].push_back(e.size());
  e.push_back({b, a, cap, 0});
}

void clear_graph() {
  for (auto c : e) {
    g[c.a].clear(), g[c.b].clear();
  }
  e.clear();
}

vector <int> ok[N];
vector <int> bs;

int ret[N];
int lol[N];
int dd[N];

int tt;
int s, t;
int used[N];

void push(int v) {
  used[v] = tt;
  for (int x : g[v]) {
    int to = e[x].b;
    if (used[to] != tt && e[x].cap > e[x].flow) {
      push(to);
    }
  }
}

int ptr[N];
int dist[N];
int init[N];
int muda[N];

bool bfs(int v) {
  queue <int> q;
  q.push(v);
  tt++;
  dist[t] = -1;
  muda[v] = tt;
  dist[v] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int y : g[v]) {
      int x = e[y].b;
      if (muda[x] != tt && e[y].flow < e[y].cap) {
        dist[x] = dist[v] + 1;
        muda[x] = tt;
        q.push(x);
      }
    }
  }
  return dist[t] != -1;
}

int soka[N];

int zhfs(int v, int mxflow) {
  if (v == t) {
    return mxflow;
  }
  if (soka[v] != tt) ptr[v] = 0;
  soka[v] = tt;
  for (int &i = ptr[v]; i < (int) g[v].size(); i++) {
    int id = g[v][i];
    if (e[id].flow < e[id].cap && dist[e[id].b] == dist[v] + 1) {
      int go = zhfs(e[id].b, min(mxflow, e[id].cap - e[id].flow));
      if (go) {
        e[id].flow += go, e[id ^ 1].flow -= go;
        return go;
      }
    }
  }
  return 0;
}

int maxflow() {
  int sum = 0;
  tt++;
  while (bfs(s)) {
    tt++;
    while (int y = zhfs(s, 10)) {
      sum += y;
    }
  }
  return sum;
}

pair <vector <int>, vector <int> > gg(int m, vector <int> verts) {
  clear_graph();
  int x = bs[m];
  tt++;
  int smh = 0;
  for (int p : verts) {
    lol[p] = tt;
    dd[p] = smh++;
    init[dd[p]] = p;
  }
  s = smh++;
  t = smh++;
  for (int p : verts) {
    int smol = 0, larg = 0;
    for (int m : real_g[p]) {
      if (lol[m] == tt) {
        if (dd[p] < dd[m])
          add_bipartite_edge(dd[p], dd[m], 1);
      } else {
        if (ret[m] < x) {
          smol++;
          //add_edge(s, dd[p], 1);
        } else {
          larg++;
          //add_edge(dd[p], t, 1);
        }
      }
    }
    for (int z : ok[p]) {
      if (z < x) {
        smol++;
        //add_edge(s, dd[p], 1);
      } else {
        //add_edge(dd[p], t, 1);
        larg++;
      }
    }
    if (smol) add_edge(s, dd[p], smol);
    if (larg) add_edge(dd[p], t, larg);
  }
  int p = maxflow();
  tt++;
  push(s);
  vector <int> vl, vr;
  for (int i = 0; i <= t; i++) {
    if (i == s || i == t) continue;
    if (used[i] == tt) vl.push_back(init[i]);
    else vr.push_back(init[i]);
  }
  return {vl, vr};
}

void solve(int l, int r, vector <int> vertset) {
  if (l >= r) return;
  if (vertset.empty()) return;
  for (int x : vertset) ret[x] = bs[l];
  if (r - l == 1) {
    for (int x : vertset) {
      ret[x] = bs[l];
    }
    return;
  }
  int m = (l + r) / 2;
  auto a = gg(m, vertset);
  for (int x : a.first) ret[x] = bs[m] - 1;
  for (int x : a.second) ret[x] = bs[m];
  solve(l, m, a.first);
  solve(m, r, a.second);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> mda;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] > 0)
        bs.push_back(a[i][j]);
      if (a[i][j] == 0) {
        mda.push_back(vs);
        id[i][j] = vs++;
      }
    }
  }
  s = vs++, t = vs++;
  sort(bs.begin(), bs.end());
  bs.resize(unique(bs.begin(), bs.end()) - bs.begin());
  ll sum = 0;
  //vector <pair <int, int> > ev;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int t = 0; t < 4; t++) {
        int x = i + dx[t], y = j + dy[t];
        if (0 <= x && x < n && 0 <= y && y < n) {
          if (a[x][y] > 0 && a[i][j] > 0) {
            sum += abs(a[i][j] - a[x][y]);
          }
          if (a[i][j] > 0 && a[x][y] == 0) {
            ok[id[x][y]].push_back(a[i][j]);
          }
          if (a[i][j] == 0 && a[x][y] == 0) {
            real_g[id[i][j]].push_back(id[x][y]);
            //add_edge(id[i][j], id[x][y], 1);
          }
        }
      }
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        a_id[id[i][j]] = e.size();
        add_edge(s, id[i][j], l_cost[i][j]);
        b_id[id[i][j]] = e.size();
        add_edge(id[i][j], t, 0);
      }
    }
  }
  */
  sum /= 2;
  solve(0, (int) bs.size(), mda);
  for (int v : mda) {
    for (int z : ok[v]) {
      sum += abs(z - ret[v]);
    }
    for (int x : real_g[v]) {
      if (v < x) {
        sum += abs(ret[v] - ret[x]);
      }
    }
  }
  cout << sum << '\n';
}//