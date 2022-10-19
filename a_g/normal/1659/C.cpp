#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n+1);
    for (int i = 0; i < n; i++) cin >> x[i+1];
    long long ans = 1e18;
    vector<long long> suff(n+2);
    for (int i = n; i >= 0; i--) {
      suff[i] = suff[i+1] + x[i];
    }
    for (int i = 0; i <= n; i++) {
      ans = min(ans, 1LL*(a+b)*x[i] + b*(suff[i+1]-1LL*(n-i)*x[i]));
    }
    cout << ans << '\n';
  }
}