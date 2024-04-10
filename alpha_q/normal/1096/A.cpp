#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int t; long long l, r;

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld %lld", &l, &r);
    assert(l + l <= r);
    printf("%lld %lld\n", l, l + l);
  }
  return 0;
}