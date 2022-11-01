#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> g[N];
map <int, int> global;
int n, a[N], in[N], out[N], ptr, fenw[N];

void go (int u = 1, int par = -1) {
  in[u] = ++ptr;
  for (int v : g[u]) if (v != par) go(v, u);
  out[u] = ptr;
}

void update (int p, int v) {
  while (p < N) fenw[p] += v, p += p & -p;
}

void range (int l, int r, int v) {
  if (l > r) return;
  update(l, v); update(r + 1, -v);
}

int get (int p) {
  int ret = 0;
  while (p) ret += fenw[p], p -= p & -p;
  return ret;
}

void dfs (map <int, int> &vals, int u = 1, int par = -1) {
  for (int v : g[u]) if (v != par) {
    map <int, int> tmp;
    dfs(tmp, v, u);
    if (tmp.find(a[u]) != tmp.end()) {
      range(in[u] + 1, in[v] - 1, 1); 
      range(out[v] + 1, out[u], 1);
    }
    if (vals.size() < tmp.size()) vals.swap(tmp);
    for (auto [key, val] : tmp) vals[key] += val;
  }
  if (vals.find(a[u]) != vals.end()) {
    range(1, in[u], 1); range(out[u] + 1, n, 1);
  }
  ++vals[a[u]];
  if (global[a[u]] > vals[a[u]]) {
    range(in[u], out[u], 1);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ++global[a[i]];
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  map <int, int> tmp; go(); dfs(tmp);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += !get(i);
  cout << ans << '\n';
  return 0;
}