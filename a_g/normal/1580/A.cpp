#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), pref(n, vector<int>(m+1));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        a[i][j] = s[j]=='1';
        pref[i][j+1] = pref[i][j]+a[i][j];
      }
    }
    int ans = 1e9;
    for (int l = 0; l < m; l++) {
      for (int r = l+3; r < m; r++) {
        // fix the left and right sides of the portal
        // if the top and bottom are x and y, then the cost is
        // b[x]+c[x+1]+...+c[y-1]+b[y] for some cost functions b and c
        // which can be rewritten as b[y]+d[y]+b[x]-d[x+1] where d is sum c
        vector<int> b(n), c(n), d(n+1);
        for (int i = 0; i < n; i++) {
          b[i] = (r-l-1)-(pref[i][r]-pref[i][l+1]);
          c[i] = pref[i][r]-pref[i][l+1]+(1-a[i][r])+(1-a[i][l]);
          d[i+1] = d[i]+c[i];
        }
        int best = b[0]-d[1];
        for (int y = 4; y < n; y++) {
          ans = min(ans, b[y]+d[y]+best);
          best = min(best, b[y-3]-d[y-2]);
        }
      }
    }
    cout << ans << '\n';
  }
}