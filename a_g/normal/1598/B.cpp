#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int, 5>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> a[i][j];
    }
    bool good = 0;
    for (int i = 0; i < 5; i++) {
      for (int j = i+1; j < 5; j++) {
        int c[4] = {0, 0, 0, 0};
        for (int k = 0; k < n; k++) {
          c[2*a[k][i]+a[k][j]]++;
        }
        if (c[0]) continue;
        if (max(c[1], c[2]) <= n/2) good = 1;
      }
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}