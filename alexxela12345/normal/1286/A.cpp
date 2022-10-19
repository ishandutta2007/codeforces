#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  int cnt1 = (n + 1) / 2;
  vector<int> pref_cnt(n + 1);
  for (int i = 0; i < n; i++) {
    pref_cnt[i + 1] = pref_cnt[i];
    if (arr[i] == 0)
      pref_cnt[i + 1]++;
    else if (arr[i] % 2 == 1)
      cnt1--;
  }
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (cnt1 + 1, vector<int> (2, 1e9)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= cnt1; j++) {
      int k = pref_cnt[i] - j;
      if (k < 0)
        continue;
      for (int last = 0; last < 2; last++) {
        if (arr[i - 1] == 0) {
          if ((j == 0 && last == 1) || (k == 0 && last == 0)) {
            continue;
          }
          if (last == 0) {
            dp[i][j][last] = min(dp[i - 1][j][last], dp[i - 1][j][1 - last] + 1);
          } else {
            dp[i][j][last] = min(dp[i - 1][j - 1][last], dp[i - 1][j - 1][1 - last] + 1);
          }
        } else {
          if (arr[i - 1] % 2 != last) {
            continue;
          }
          dp[i][j][last] = min(dp[i - 1][j][last], 1 + dp[i - 1][j][1 - last]);
        }
      }
    }
  }
  cout << min(dp[n][cnt1][0], dp[n][cnt1][1]) << endl;
}