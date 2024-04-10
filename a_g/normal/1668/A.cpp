#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (m == 1) {
      cout << (n > 2 ? -1 : n - 1) << '\n';
      continue;
    }
    int d = n-m;
    cout << 2*(m-1) + 4*(d/2) + (d%2) << '\n';
  }
}