#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 2>> z(n+1);
    z[0][0] = 0, z[0][1] = 0;
    for (int i = 0; i < n; i++) {
      z[i+1] = z[i];
      z[i+1][s[i]=='0']++;
    }
    int m = z[n][0];
    int low = -1;
    int high = n;
    while (high-low > 1) {
      int mid = (low+high)/2;
      bool win = 0;
      for (int i = 0; i < n; i++) {
        array<int, 2> base = {z[i][0]+(m-mid), -1};
        auto it = lower_bound(z.begin(), z.end(), base);
        if (it == z.end()) break;
        else if ((*it)[1]-z[i][1] <= mid) {
          win = 1;
          break;
        }
      }
      if (win) high = mid;
      else low = mid;
    }
    cout << high << '\n';
  }
}