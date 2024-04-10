#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long g = __gcd(n + 1, 4 * n);
    long long ans = (4 * n) / g + 1;
    printf("%lld\n", ans);
  }
  return 0;
}