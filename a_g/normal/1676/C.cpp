#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> z(n);
    for (string& x: z) cin >> x;
    int best = 1e9;

    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        int cost = 0;
        for (int k = 0; k < m; k++) {
          int u = abs(z[i][k]-z[j][k]);
          cost += u;
        }
        best = min(best, cost);
      }
    }
    cout << best << '\n';
  }
}