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

  ll solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (auto& x : a) {
      cin >> x;
      cnt[x]++;
    }

    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    map<int, int> rev_a;
    for (int i = 0; i < n; ++i) {
      rev_a[a[i]] = i;
    }

    g.resize(n);
    for (int i = 0; i < n; ++i) {
      g[i].push_back({cnt[a[i]], i});
    }
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      int x_i = rev_a[x];
      int y_i = rev_a[y];
      g[x_i].push_back({cnt[y], y_i});
      g[y_i].push_back({cnt[x], x_i});
    }
    for (int i = 0; i < n; ++i) {
      sort(g[i].begin(), g[i].end(), [](auto& l, auto& r) {return pair(l.first, -l.second) < pair(r.first, -r.second);});
    }

    map<int, vector<int>> xi_by_cnt;
    ll answer = 0;
    for (int i = n - 1; i >= 0; --i) {
      xi_by_cnt[cnt[a[i]]].push_back(i);
    }

    //for (auto e : g[3]) cout << e.first << " " << e.second << " " << endl;

    for (int it = 0; it < n; ++it) {
      int x = a[it];
      int cnt_of_x = cnt[x];
      int ptr = 0;
      for (const auto& [cnt, ids] : xi_by_cnt) {
        for (auto i : ids) {
          while (ptr < (int)g[it].size() && pair(g[it][ptr].first, -g[it][ptr].second) < pair(cnt, -i)) {
            ++ptr;
          }
          if (ptr == (int)g[it].size() || (ptr < (int)g[it].size() && (g[it][ptr].first != cnt || g[it][ptr].second != i))) {
            answer = max(answer, (ll)(cnt_of_x + cnt) * ((ll)x + a[i]));
            break;
          }
        }
      }
    }
    return answer;
  }

private:
  vector<int> a;
  unordered_map<int, int> cnt;
  vector<vector<pair<int, int>>> g;

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << Solver{}.solve() << "\n";
  }
}