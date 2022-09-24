#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 1'000'000;
  cin >> n;
  vector<vector<int>> g(n);
//  int H = 1;
//  int need = H;
  for (int i = 1; i < n; i++) {
    int x;
//    if (need > 0) {
//      need--;
//      x = i;
//    } else {
//      H++;
//      need = H;
//      x = 1;
//    }
    cin >> x;
    x--;
    g[x].push_back(i);
    g[i].push_back(x);
  }

  vector<int> sz(n);
  vector<ll> du(n);
  vector<vector<int>> w(n);
  function<void(int, int)> dfs = [&](int x, int p) {
    sz[x] = 1;
    for (int i: g[x]) {
      if (i != p) {
        dfs(i, x);
        sz[x] += sz[i];
        w[x].push_back(sz[i]);
        du[x] += du[i] + sz[i];
      }
    }
    if (p != -1) {
      w[x].push_back(n - sz[x]);
    }
  };
  dfs(0, -1);
  function<void(int, int, ll, ll)> propagate = [&](int x, int p, ll sumD, ll sumSz) {
    ll distChild = du[x];
    du[x] += sumD;
    for (int i: g[x]) {
      if (i != p) {
        propagate(i, x, sumD + sumSz + (distChild - (du[i] + sz[i])) + sz[x] - sz[i], sumSz + sz[x] - sz[i]);
      }
    }
  };
  propagate(0, -1, 0, 0);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sort(w[i].begin(), w[i].end());
    if (w[i].back() >= (n - 1) / 2) {
      ll cur = w[i].back();
      ans = max(ans, du[i] + ((n - 1) - cur) * cur);
    } else {
      vector<pii> items;
      for (int ws: w[i]) {
        if (items.empty() || items.back().first != ws) {
          items.emplace_back(ws, 1);
        } else {
          items.back().second++;
        }
      }
      ll cur = 0;
      // rukzak
      vector<char> dp(n / 2 + 1), new_dp(n / 2 + 1);
      dp[0] = true;
      vector<int> ques(n / 2 + 1);
      vector<int> ques_cnt(n / 2 + 1);
      for (auto[ws, cnt]: items) {
        fill(ques.begin(), ques.begin() + min(n / 2 + 1, ws), '\0');
        fill(ques_cnt.begin(), ques_cnt.begin() + min(n / 2 + 1, ws), '\0');
        new_dp = dp;
        for (int j = 0; j != -1; j += ws) {
          for (int rem = 0; rem < ws; rem++) {
            int rj = j + rem;
            if (rj >= dp.size()) {
              goto label;
            }
            ques[rem] += dp[rj];
            ques_cnt[rem]++;
            new_dp[rj] = ques[rem] != 0;
            if (ques_cnt[rem] >= cnt + 1) {
              ques[rem] -= dp[rj - ws * cnt];
            }
          }
        }
        label:
        swap(dp, new_dp);
        if (dp[(n - 1) / 2]) {
          break;
        }
      }

      for (; cur <= n / 2; cur++) {
        if (dp[cur]) {
          ans = max(ans, du[i] + ((n - 1) - cur) * cur);
        }
      }
    }
  }
  cout << ans + n;

  return 0;
}