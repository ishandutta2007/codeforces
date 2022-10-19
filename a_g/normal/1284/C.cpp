#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;
int fact[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % m;
  }
  // sum from l = 1 to n of (n+1-l)*(n+1-l)*l!*(n-l)!
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    int z = 1LL*(n+1-l)*(n+1-l) % m;
    z = 1LL*fact[l]*z % m;
    z = 1LL*fact[n-l]*z % m;
    ans += z;
    if (ans >= m) ans -= m;
  }
  cout << ans << '\n';
}