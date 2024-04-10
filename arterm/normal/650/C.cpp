#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e6 + 10;

int n, m;
int all;
int r[M], p[M];
int d[M];
bool used[M];
vector<vector<pair<int, int>>> row, col;
vector<int> g[M];
vector<pair<int, int>> edg;

void add(int from, int to) {
  edg.emplace_back(from, to);
}

void ini() {
  for (int i = 0; i < M; ++i) {
    p[i] = i;
    r[i] = 0;
  }
}

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  if (x == y)
    return;
  if (r[x] < r[y])
    swap(x, y);
  r[x]++;
  p[y] = x;
}

void read() {
  cin >> n >> m;
  all = n * m;
  row.resize(n);
  col.resize(m);

  for (int i = 0, id = 0; i < n; ++i)
    for (int j = 0; j < m; ++j, ++id) {
      int v;
      cin >> v;
      row[i].emplace_back(v, id);
      col[j].emplace_back(v, id);
    }
}

void build() {
  for (auto &r : row) {
    sort(r.begin(), r.end());
    for (int j = 0; j + 1 < m; ++j)
      if (r[j].first < r[j + 1].first) {
        add(r[j + 1].second, r[j].second);
      } else {
        uni(r[j + 1].second, r[j].second);
      }
  }

  for (auto &c : col) {
    sort(c.begin(), c.end());
    for (int i = 0; i + 1 < n; ++i)
      if (c[i].first < c[i + 1].first) {
        add(c[i + 1].second, c[i].second);
      } else {
        uni(c[i + 1].second, c[i].second);
      }
  }

  for (int i = 0; i < all; ++i)
    p[i] = get(i);

  for (auto e : edg) {
    int from = get(e.first);
    int to = get(e.second);
    //cerr << from << " -> " << to << endl;
    g[from].push_back(to);
  }
}

int dfs(int v) {
  if (used[v])
    return d[v];

  used[v] = true;
  d[v] = 1;
  for (int to : g[v])
    d[v] = max(d[v], dfs(to) + 1);
  return d[v];
}

void kill() {
  for (int v = 0; v < all; ++v)
    d[v] = dfs(get(v));

  for (int i = 0, id = 0; i < n; ++i, cout << "\n")
    for (int j = 0; j < m; ++j, ++id)
      cout << d[id] << " ";
}


int main() {
  ios_base::sync_with_stdio(false);
  ini();
  read();
  build();
  kill();
}