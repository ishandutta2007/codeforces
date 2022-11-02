#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

long long n, k;

int main() {
  cin >> n >> k;
  long long h = (k >> 1);
  long long ans = max(0LL, h - max(1LL, k - n) + 1);
  if (h + h == k and h <= n) --ans;
  cout << ans << '\n';
  return 0;
}