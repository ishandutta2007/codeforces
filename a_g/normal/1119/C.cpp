#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> r(n), c(m);
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        r[i] ^= x;
        c[j] ^= x;
      }
    }
  }
  for (int x: r) {
    if (x) {
      cout << "No\n";
      return 0;
    }
  }
  for (int x: c) {
    if (x) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}