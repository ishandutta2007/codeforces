#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

int n, k, a[N];

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &k);
  scanf("%d", a + 1);
  int r = a[1] % k, flag = 0, small = a[1];
  for (int i = 2; i <= n; ++i) {
    scanf("%d", a + i);
    small = min(small, a[i]);
    if (a[i] % k != r) {
      flag = 1;
    }
  }
  if (flag) {
    puts("-1");
    return 0;
  }
  long long moves = 0;
  for (int i = 1; i <= n; ++i) {
    moves += (1ll * a[i] - small)/(1ll * k);
  }
  printf("%lld\n", moves);
  return 0;
}