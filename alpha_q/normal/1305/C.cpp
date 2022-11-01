#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, m; ll a[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  if (n > m) {
    cout << 0 << '\n';
    return 0;
  }
  ll ans = 1 % m;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ll cur = abs(a[i] - a[j]) % m;
      ans = ans * cur % m;
    }
  }
  cout << ans << '\n';
  return 0;
}