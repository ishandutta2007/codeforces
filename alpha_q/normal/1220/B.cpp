#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1010;

int n; ll a[N][N];

ll sq (ll x) {
  ll ret = sqrtl(x) - 5;
  if (ret < 0) ret = 0;
  while (ret * ret < x) ++ret;
  return ret;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%lld", a[i] + j);
    }
  }
  ll x = sq((a[1][2] * a[1][3]) / a[2][3]);
  ll y = sq((a[1][2] * a[2][3]) / a[1][3]);
  printf("%lld %lld ", x, y);
  for (int i = 3; i <= n; ++i) {
    ll cur = sq((a[1][i] * a[2][i]) / (a[1][2]));
    printf("%lld ", cur);
  }
  cout << '\n';
  return 0;
}