#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> b(n), c(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    b[i] = x+y;
    c[i] = x;
    ans += y;
  }
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  for (int i = 0; i < n-1; i++) {
    ans += max(0, c[i+1]-b[i]);
  }
  cout << ans << '\n';
}