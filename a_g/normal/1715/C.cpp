#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> contrib(n-1);
  for (int i = 0; i < n-1; i++) {
    contrib[i] = 1LL*(i+1)*(n-1-i);
  }
  vector<int> a(n);
  long long ans = 1LL*n*(n+1)/2;
  auto upd = [&] (int i, int x) {
    if (i > 0 && a[i] != a[i-1]) ans -= contrib[i-1];
    if (i < n-1 && a[i] != a[i+1]) ans -= contrib[i];
    a[i] = x;
    if (i > 0 && a[i] != a[i-1]) ans += contrib[i-1];
    if (i < n-1 && a[i] != a[i+1]) ans += contrib[i];
  };

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    upd(i, x);
  }
  while (m--) {
    int i, x;
    cin >> i >> x;
    upd(i-1, x);
    cout << ans << '\n';
  }
}