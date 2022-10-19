#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n < 2*k-1) {
      cout << "-1\n";
      continue;
    }
    vector<vector<char>> ans(n, vector<char>(n, '.'));
    for (int i = 0; i < k; i++) {
      ans[2*i][2*i] = 'R';
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}