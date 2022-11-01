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
    int n, m;
    cin >> n >> m;
    g.resize(n);
    revg.resize(n);

    vector<map<int, int>> gg(n);

    for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      gg[--v][--u]++;
    }

    vector<int> g_size(n, 0);
    for (int i = 0; i < n; ++i) {
      for (auto [u, cnt] : gg[i]) {
        g[i].push_back({u, cnt});
        g_size[i] += cnt;
        revg[u].push_back({i, cnt});
      }
    }

    ptr.resize(n, 0);
    val.resize(n, INF);
    val[n - 1] = 0;

    set<pair<int, ll>> s;
    s.insert({0, n - 1});

    used.resize(n, false);

    while (!s.empty()) {
      auto v = s.begin()->second;
      used[v] = true;
      s.erase(s.begin());

      for (auto [u, cnt] : revg[v]) {
        if (used[u]) {
          continue;
        }
        ll new_val = val[v] + 1 + (g_size[u] - ptr[u] - cnt);
        //cout << v << " " << u << " " <<  new_val << ", val[v]: " << val[v] << ", gsize[u]: " << g_size[u] << ", ptr[u]: " << ptr[u] << endl;
        ptr[u] += cnt;
        if (new_val < val[u]) {
          s.erase({val[u], u});
          val[u] = new_val;
          s.insert({val[u], u});
        }
      }
    }

    //for (int i = 0; i < n; ++i) cout << val[i] << " ";cout << endl;
    cout << val[0] << "\n";


  }

private:
  vector<vector<pair<int, int>>> g, revg;
  vector<int> g_size;
  vector<int> ptr;
  vector<ll> val;
  vector<int> used;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}