#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

int n, a[N];

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int at = 1, i = 1, j = n; at <= n; at += 2, ++i, --j) {
    a[at] = i;
    a[at + 1] = j; 
  }
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += (long long) (a[i] + a[i + 1]) % (n + 1);
  }
  printf("%lld\n", ans);
  return 0;
}