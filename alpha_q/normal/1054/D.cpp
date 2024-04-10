#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

map <int, int> f;
int n, k, a[N], b[N];

long long comb (int x) {
  return x * 1LL * (x - 1LL) / 2LL;
}

int main() {
  cin >> n >> k;
  int yo = (1LL << k) - 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] ^= a[i - 1];
    b[i] = yo ^ a[i];
  }
  ++f[0];
  long long ans = comb(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (f[a[i]] < f[b[i]]) {
      ++f[a[i]];
    } else {
      ++f[b[i]];
    }
  }
  for (auto it : f) {
    ans -= comb(it.second);
  }
  cout << ans << '\n';
  return 0;
}