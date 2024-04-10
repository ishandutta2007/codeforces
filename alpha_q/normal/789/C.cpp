#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

int n;
long long a[N], b[N], c[N];

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  --n;
  for (int i = 1; i <= n; ++i) {
    b[i] = abs(a[i] - a[i + 1]);
  }
  c[0] = 0, c[1] = b[1];
  long long ans = max(0ll, c[1]);
  for (int i = 2; i <= n; ++i) {
    c[i] = b[i];
    c[i] = max(c[i], b[i] - b[i - 1] + c[i - 2]);
    ans = max(ans, c[i]);
  }
  printf("%lld\n", ans);
  return 0;
}