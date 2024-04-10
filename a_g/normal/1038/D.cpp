#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  if (n == 1) {
    cout << a[0] << '\n';
    return 0;
  }

  sort(a.begin(), a.end());
  long long ans = 0;
  for (int x: a) ans += abs(x);
  if (a[0] > 0) ans -= 2*a[0];
  if (a[n-1] < 0) ans += 2*a[n-1];
  cout << ans << '\n';
}