#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      a[i][j] -= x;
    }
  }
  
  int d[2] = {0, 0};
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    d[0] += a[0][i];
    d[1] += a[1][i];
    if (d[0] > 0 && d[1] < 0) {
      ans++;
      d[0]--;
      d[1]++;
    }
    if (d[0] < 0 && d[1] > 0) {
      ans++;
      d[0]++;
      d[1]--;
    }
    ans += abs(d[0])+abs(d[1]);
  }

  if (d[0] != 0 || d[1] != 0) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
}