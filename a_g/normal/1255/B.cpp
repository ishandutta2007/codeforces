#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    if (n == 2 || m < n) {
      cout << "-1\n";
      continue;
    }
    cout << 2*accumulate(a.begin(), a.end(), 0) << '\n';
    for (int i = 1; i <= n; i++) {
      cout << i << " " << (i == n ? 1 : i+1) << '\n';
    }
  }
}