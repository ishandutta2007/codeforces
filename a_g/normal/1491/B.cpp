#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool free = 0;
    for (int i = 0; i < n-1; i++) {
      if (abs(a[i+1]-a[i]) > 1) free = 1;
    }
    if (free) {
      cout << "0\n";
      continue;
    }
    if (count(a.begin(), a.end(), a[0]) == n) {
      cout << v+min(u, v) << '\n';
      continue;
    }
    cout << min(u, v) << '\n';
  }
}