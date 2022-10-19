#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e6+5;
int f[N][2];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 3; i < N; i++) {
    f[i][1] = (1LL + f[i-1][0]+2*f[i-2][0]) % MOD;
    f[i][0] = (max(f[i-1][0], f[i-1][1])+2LL*max(f[i-2][0], f[i-2][1])) % MOD;
  }
  // mixing MOD with comparison is very sketchy but it will work here I guess
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (4LL*max(f[n][1], f[n][0])) % MOD << '\n';
  }
}