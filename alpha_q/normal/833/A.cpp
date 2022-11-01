#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%lld %lld", &a, &b);
    long long c = a * b;
    long long lo = 0, hi = 1000000;
    while (lo < hi) {
      long long mid = lo + hi >> 1;
      if (mid * mid * mid < c) lo = mid + 1;
      else hi = mid;
    }
    if (lo * lo * lo != c) {
      puts("No");
      continue;
    }
    if (a % lo or b % lo) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}