#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  long long ans = 0;

  int odds = 0;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    if (a[i]&1) {
      a[i] -= 1;
      odds++;
    }
    while (a[i] >= 2 && odds > 0) {
      odds--;
      a[i] -= 2;
      ans++;
    }
    s += a[i];
  }
  ans += s/3;
  cout << ans << '\n';
}