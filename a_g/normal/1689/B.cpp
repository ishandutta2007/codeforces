#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& x: p) cin >> x;
    if (n == 1) {
      cout << "-1\n";
      continue;
    }
    vector<bool> used(n+1);
    vector<int> ans(n);
    for (int i = 0; i < n-2; i++) {
      for (int j = 1; j <= n; j++) {
        if (!used[j] && j != p[i]) {
          ans[i] = j;
          used[j] = 1;
          break;
        }
      }
    }
    int z = n-2;
    for (int j = 1; j <= n; j++) {
      if (!used[j]) ans[z++] = j;
    }
    if (ans[n-2] == p[n-2] || ans[n-1] == p[n-1]) {
      swap(ans[n-2], ans[n-1]);
    }
    for (int x: ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}