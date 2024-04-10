#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2*n, vector<int>(n)), G(2*n);
    int ans = 1;
    vector<bool> active(2*n, 1), done(2*n);
    vector<vector<int>> freq(n, vector<int>(n));
    for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        a[i][j]--;
        freq[j][a[i][j]]++;
      }
    }
    vector<int> latin_set;

    for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < 2*n; j++) {
        for (int k = 0; k < n; k++) {
          if (a[i][k] == a[j][k]) {
            G[i].push_back(j);
            G[j].push_back(i);
          }
        }
      }
    }
    
    auto deactivate = [&] (int i) {
      if (!active[i]) return;
      active[i] = 0;
      for (int j = 0; j < n; j++) {
        freq[j][a[i][j]]--;
      }
    };

    auto select = [&] (int i) {
      latin_set.push_back(i);
      deactivate(i);
      for (int k: G[i]) deactivate(k);
    };

    while ((int)latin_set.size() < n) {
      bool ch = 0;
      for (int i = 0; i < 2*n; i++) {
        if (active[i]) {
          for (int j = 0; j < n; j++) {
            if (freq[j][a[i][j]] == 1) {
              select(i);
              ch = 1;
              break;
            }
          }
        }
      }
      if (!ch) {
        ans *= 2;
        if (ans >= MOD) ans -= MOD;
        for (int i = 0; i < 2*n; i++) {
          if (active[i]) {
            select(i);
            break;
          }
        }
      }
    }

    
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << latin_set[i]+1 << " \n"[i+1==n];
    }
  }
}