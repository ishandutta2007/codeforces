#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    bool ok = 1;
    if (k <= 1) ok = 0;
    if (k == 2) ok = (n == 1);
    if (k == 3) ok = (m == 1LL*n*(n-1)/2);
    if (k > 3) ok = (m >= n-1);
    if (m > 1LL*n*(n-1)/2) ok = 0;
    cout << (ok ? "YES" : "NO") << '\n';
  }
}