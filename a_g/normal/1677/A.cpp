#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    for (int& x: a) x--;
    vector<vector<int>> lt(n, vector<int>(n));
    for (int i = 1; i < n; i++) {
      if (a[i] < n-1) lt[i-1][a[i]+1]++;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        lt[i][j] += lt[i][j-1];
      }
    }
    for (int i = n-2; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        lt[i][j] += lt[i+1][j];
      }
    }
    
    long long ans = 0;

    for (int i = 1; i < n; i++) {
      for (int j = i+1; j < n-1; j++) {
        // pick b, c
        int u = lt[j][a[i]];
        int v = (a[j])-lt[i-1][a[j]];
        ans += u*v;
      }
    }

    cout << ans << '\n';
  }
}