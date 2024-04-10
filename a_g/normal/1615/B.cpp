#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int b, int n) {
  int k = 1<<b;
  int ans = k*(n/(2*k));
  if (n % (2*k) >= k) ans += (n-(2*k)*(n/(2*k)) - k + 1);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    int ans = 1e9;
    for (int b = 0; b < 25; b++) ans = min(ans, (r-l+1)-(f(b, r) - f(b, l-1)));
    cout << ans << '\n';
  }
}