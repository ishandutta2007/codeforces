#include <bits/stdc++.h> 

using namespace std;

const int INF = 1000000;

long long n, k;

int main (int argc, char const *argv[]) {
  scanf("%lld %lld", &n, &k);
  if (k > INF) {
    puts("-1");
    return 0;
  }
  long long sum = (k * (k + 1))/2;
  long long up = n;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    long long j = n/i;
    if (sum <= i) up = min(up, i);
    if (sum <= j) up = min(up, j);
  }
  if (sum > up) {
    puts("-1");
    return 0;
  }
  long long g = n/up;
  for (int i = 1; i < k; ++i) {
    printf("%lld ", i * 1ll * g);
    up -= i;
  }
  printf("%lld\n", g * up);
  return 0;
}