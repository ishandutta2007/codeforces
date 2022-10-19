#ifndef DEBUG
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }
  }
  vector<ll> ans(1 << (n - 1));
  vector<vector<vector<int>>> dp(1 << n, vector<vector<int>> (n));
  for (int mask = 0; mask < (1 << n); mask++) {
    for (int last = 0; last < n; last++) {
      if (mask & (1 << last)) {
        int cnt = __builtin_popcount(mask);
        dp[mask][last].resize(1 << (cnt - 1));
        if (cnt == 1) {
          dp[mask][last][0] = 1;
        }
        for (int i = 0; i < n; i++) {
          if ((mask & (1 << i)) && i != last) {
            int pr = i;
            int maskp = mask ^ (1 << last);
            for (int mask2 = 0; mask2 < (int) dp[maskp][pr].size(); mask2++) {
              dp[mask][last][mask2 * 2 + g[last][pr]] += dp[maskp][pr][mask2];
            }
          }
        }
      }
    }
  }
  vector<vector<int>> inds(1 << n);
  vector<int> revmask(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        inds[i].push_back(j);
        int kek = n - n / 2 - 2 - j;
        if (kek >= 0)
          revmask[i] ^= 1 << kek;
      }
    }
  }
  int all = (1 << n) - 1;

  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = __builtin_popcount(mask);
    if (cnt == n / 2) {
      int mask2 = all ^ mask;
      for (int last1 : inds[mask]) {
        for (int m1 = 0; m1 < dp[mask][last1].size(); m1++) {
          for (int last2 : inds[mask2]) {
            for (int m2 = 0; m2 < dp[mask2][last2].size(); m2++) {
              int ansmask = revmask[m2];
              ansmask += g[last1][last2] << (n - n / 2 - 1);
              ansmask += m1 << (n - n / 2);
              ans[ansmask] += 1LL * dp[mask][last1][m1] * dp[mask2][last2][m2];
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}