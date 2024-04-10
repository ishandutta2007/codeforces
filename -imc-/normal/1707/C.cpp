#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

vector<vector<int>> e;

struct dsu_t {
  vector<int> p;

  dsu_t(int n): p(n) { iota(all(p), 0); }

  int get(int v) { return p[v] == v ? v : (p[v] = get(p[v])); }

  bool unite(int u, int v) {
    u = get(u);
    v = get(v);
    if (p[u] != p[v]) {
      p[u] = v;
      return true;
    }
    return false;
  }
};

int counter;
vector<int> in_time, out_time;
vector<int> add, res;

bool is_pc(int p, int c) {
  return in_time[c] > in_time[p] && out_time[c] < out_time[p];
}

const int logMaxN = 17;
vector<array<int, logMaxN>> jmp;

void dfs(int v, int p) {
  in_time[v] = ++counter;
  jmp[v][0] = p;

  for (int u : e[v]) {
    if (u != p) {
      dfs(u, v);
    }
  }

  out_time[v] = ++counter;
}

void xdfs(int v, int p, int sum = 0) {
  res[v] = sum + add[v];

  for (int u : e[v]) {
    if (u != p) {
      xdfs(u, v, res[v]);
    }
  }
}

int pre_lca(int p, int c) {
  assert(is_pc(p, c));

  for (int l = logMaxN - 1; l >= 0; --l) {
    if (jmp[c][l] != p && !is_pc(jmp[c][l], p)) {
      c = jmp[c][l];
    }
  }
  assert(!is_pc(c, p));
  assert(jmp[c][0] == p);
  return c;
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  e.clear();
  e.resize(n);
  counter = 0;
  in_time.assign(n, 0);
  out_time.assign(n, 0);
  add.assign(n, 0);
  res.assign(n, 0);
  jmp.clear();
  jmp.resize(n);

  dsu_t dsu(n);

  vector<pair<int, int>> excluded;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;

    if (dsu.unite(u, v)) {
      e[u].push_back(v);
      e[v].push_back(u);
    } else {
      excluded.push_back({u, v});
    }
  }

  dfs(0, 0);

  for (int l = 1; l < logMaxN; ++l) {
    for (int i = 0; i < n; ++i) {
      jmp[i][l] = jmp[jmp[i][l - 1]][l - 1];
    }
  }

  for (auto e : excluded) {
    int u = e.first;
    int v = e.second;

    if (!is_pc(u, v) && !is_pc(v, u)) {
      ++add[0];
      --add[u];
      --add[v];
    } else {
      if (!is_pc(u, v)) {
        swap(u, v);
      }
      assert(is_pc(u, v));

      int l = pre_lca(u, v);
      ++add[l];
      --add[v];
    }
  }

  xdfs(0, 0);

  string ans(n, '0');
  for (int i = 0; i < n; ++i) {
    ans[i] = (res[i] == 0) ? '1' : '0';
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}