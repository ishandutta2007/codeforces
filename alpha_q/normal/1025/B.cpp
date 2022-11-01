#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n;
long long a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", a + i, b + i);
  }
  set <long long> cand;
  long long x = a[1];
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      cand.insert(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    cand.insert(x);
  }
  x = b[1];
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      cand.insert(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    cand.insert(x);
  }
  for (long long p : cand) {
    int good = 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % p and b[i] % p) {
        good = 0;
        break;
      }
    }
    if (good) {
      printf("%lld\n", p);
      return 0;
    }
  }
  puts("-1");
  return 0;
}