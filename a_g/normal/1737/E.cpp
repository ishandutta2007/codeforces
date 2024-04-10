#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+5;
int p[N], f[N], g[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  p[0] = 1;
  for (int i = 1; i < N; i++) {
    p[i] = (p[i-1]&1 ?  (p[i-1]+MOD)/2 : p[i-1]/2);
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      f[i] = p[(i+1)/2-(i==n)];
    }
    g[n+1] = 0;
    for (int i = n; i >= 1; i--) {
      if (2*i <= n) {
        f[i] = 1LL*f[i]*(1-g[2*i]) % MOD;
        if (f[i] < 0) f[i] += MOD;
      }
      g[i] = g[i+1]+f[i];
      if (g[i] > MOD) g[i] -= MOD;
    }
    for (int i = 1; i <= n; i++) cout << f[i] << '\n';
  }
}