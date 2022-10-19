#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+8;
int a[N], d[N], bad[N], fib[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q, MOD;
  cin >> n >> q >> MOD;
  fib[1] = 1;
  fib[2] = 1;
  for (int i = 3; i < N; i++) {
    fib[i] = (fib[i-1] + fib[i-2]) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    a[i] = (a[i]-b)%MOD;
  }

  int z = 0;
  for (int i = 1; i <= n+2; i++) {
    if (i == 1) d[i] = a[i];
    else d[i] = (0LL + a[i] - a[i-1] - a[i-2]) % MOD;
    bad[i] = (d[i] != 0);
    z += bad[i];
  }

  while (q--) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    int sign = (c == 'A' ? 1 : -1);
    d[l] = (d[l] + sign) % MOD;
    d[r+1] = (d[r+1] - sign * fib[r-l+2]) % MOD;
    d[r+2] = (d[r+2] - sign * fib[r-l+1]) % MOD;
    for (int i: {l, r+1, r+2}) {
      z += (d[i] != 0) - bad[i];
      bad[i] = (d[i] != 0);
    }
    cout << (z ? "NO" : "YES") << '\n';
  }
}