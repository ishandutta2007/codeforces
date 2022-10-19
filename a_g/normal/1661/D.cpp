#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> b(n);
  for (long long& x: b) cin >> x;
  vector<long long> ops(n);
  long long ans = 0;
  long long c = 0, y = 0;
  for (int i = n-1; i >= 0; i--) {
    int z = min(i+1, k);
    c -= y;
    if (i+k < n) y -= ops[i+k];
    b[i] -= c;
    long long u = max(0LL, (b[i]+z-1)/z);
    ans += u;
    c += 1LL * z * u;
    y += u;
    ops[i] = u;
  }
  cout << ans << '\n';
}