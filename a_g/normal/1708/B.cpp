#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> ans(n);
    bool good = 1;
    for (int i = 0; i < n; i++) {
      ans[i] = (i+1)*(r/(i+1));
      if (ans[i] < l) good = 0;
    }
    if (good) {
      cout << "YES\n";
      for (int x: ans) {
        cout << x << ' ';
      }
      cout << '\n';
    }
    else {
      cout << "NO\n";
    }
  }
}