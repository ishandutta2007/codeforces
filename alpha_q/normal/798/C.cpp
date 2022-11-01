#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;

int n, a[N];

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  int gcd = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    gcd = __gcd(gcd, a[i]);
    a[i] %= 2;
  }
  puts("YES");
  if (gcd > 1) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] == 1) {
      if (a[i + 1] == 1) {
        ++ans;
      } else {
        ans += 2;
      }
      a[i] = a[i + 1] = 0;
    }
  }
  if (a[n] == 1) {
    ans += 2;
    a[n] = 0;
  }
  printf("%d\n", ans);
  return 0;
}