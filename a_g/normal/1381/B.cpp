#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(2*n), q(2*n);
    for (int i = 0; i < 2*n; i++) {
      cin >> p[i];
      p[i]--;
      q[p[i]] = i;
    }

    int mx = 2*n-1;
    vector<bool> taken(2*n);
    int l = 2*n;
    vector<int> lengths;
    while (mx >= 0) {
      lengths.push_back(l-q[mx]);
      for (int i = q[mx]; i < l; i++) {
        taken[p[i]] = 1;
      }
      l = q[mx];
      if (l == 0) break;
      while (mx >= 0 && taken[mx]) mx--;
    }

    bitset<2005> dp;
    dp[0] = 1;
    for (int k: lengths) {
      dp |= dp<<k;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
  }
}