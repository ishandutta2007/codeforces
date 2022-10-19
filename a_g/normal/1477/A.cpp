#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long& x: a) cin >> x;
    long long g = 0;
    for (int i = 0; i < n-1; i++) {
      g = __gcd(g, a[i+1]-a[i]);
    }
    g = abs(g);
    if (g == 0) {
      cout << (k == a[0] ? "YES" : "NO") << '\n';
      continue;
    }
    auto mod = [&] (long long k, long long g) {
      long long ans = k%g;
      if (ans < 0) ans += g;
      return ans;
    };
    cout << (mod(k, g) == mod(a[0], g) ? "YES" : "NO") << '\n';
  }
}