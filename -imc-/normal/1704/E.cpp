#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

vector<vector<int>> e;
vector<vector<int>> re;
vector<bool> used;
vector<li> f;
vector<li> a;

const int MOD = 998244353;

void dfs(int v) {
  used[v] = true;

  for (int u : re[v]) {
    if (!used[u]) {
      dfs(u);
    }
    (f[v] += f[u]) %= MOD;
  }
  (f[v] += a[v]) %= MOD;
}

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  a.resize(n);
  for (auto& x : a) cin >> x;

  e.clear();
  e.resize(n);
  re.clear();
  re.resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    e[u].push_back(v);
    re[v].push_back(u);
  }

  int add_t = 0;
  for (int t = 0; t < 1000; ++t) {
    bitset<1001> now{};
    bool have = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] > 0) {
        now[i] = true;
        have = true;
      }
    }
    if (!have) break;
    for (int i = 0; i < n; ++i) {
      if (now[i]) {
        --a[i];
        for (int x : e[i]) {
          ++a[x];
        }
      }
    }
    ++add_t;
  }

  f.assign(n, 0);
  used.assign(n, false);
  int sink = -1;
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
    if (e[i].size() == 0) {
      assert(sink == -1);
      sink = i;
    }
  }
  assert(sink != -1);

  li ans = (f[sink] + add_t) % MOD;

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}