#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

class Solver {
public:

  void solve() {
    int n;
    cin >> n;
    h.resize(n);
    for (auto& e : h) cin >> e;

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
      int v, u;
      cin >> v >> u;
      g[--v].push_back(--u);
      g[u].push_back(v);
    }

    auto it = max_element(h.begin(), h.end()) - h.begin();

    d.resize(n);
    answer = 0;
    dfs(it);
    cout << answer << endl;
  }

private:
  vector<ll> h;
  vector<vector<int>> g;
  vector<ll> d;
  ll answer;

  void dfs(int v, int par = -1) {
    vector<ll> ch;
    for (auto u : g[v]) {
      if (u == par) continue;
      dfs(u, v);
      ch.push_back(d[u]);
    }

    if (ch.empty()) {
      d[v] = h[v];
      return;
    }


    sort(ch.begin(), ch.end());
    for (int i = 0; i + 1 < (int)ch.size(); ++i) {
      answer += ch[i];
    }
    d[v] = max(h[v], ch.back());

    if (par == -1) {
      if (ch.size() == 1u) {
        answer += 2 * d[v];
      } else {
        answer -= ch[(int)ch.size() - 2];
        answer += 2 * d[v];
      }
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}