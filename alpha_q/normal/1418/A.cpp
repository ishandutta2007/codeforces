#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18 + 69;

int t; ll x, y, k;

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    scanf("%lld %lld %lld", &x, &y, &k);
    ll stick = k + y * k, power = 1, ans = (stick + x - 3) / (x - 1) + k;
    printf("%lld\n", ans);
  }
  return 0;
}