#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> dists(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i]--;
    }
    bool good = 1;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      dists[p-1] = i;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = dists[i] - dists[b[i]];
      if (ans[i] < 0) good = 0;
    }
    if (good) {
      for (int d: ans) cout << d << ' ';
      cout << '\n';
    }
    else cout << "-1\n";
  }
}