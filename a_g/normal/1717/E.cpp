#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+5;
int not_phi[N];
int f[N];

void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    not_phi[i] = i/__gcd(n, i);
  }
  for (int i = 1; i < N; i++) {
    for (int j = 2*i; j < N; j += i) {
      not_phi[j] -= not_phi[i];
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 2; j*i < N; j++) {
      add(f[j*i], 1LL*(j-1)*not_phi[i] % MOD);
    }
  }

  int ans = 0;
  for (int c = 1; c <= n; c++) {
    ans = (ans+1LL*c*f[n-c]) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}