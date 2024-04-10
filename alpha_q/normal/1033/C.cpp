#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;

int n, a[N], inv[N], f[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    inv[a[i]] = i;
  }
  for (int i = n; i > 0; --i) {
    int pos = inv[i];
    f[pos] = 0;
    for (int j = pos + i; j <= n; j += i) {
      if (a[j] > i and !f[j]) {
        f[pos] = 1;
        break;
      } 
    }
    if (!f[pos]) {
      for (int j = pos - i; j > 0; j -= i) {
        if (a[j] > i and !f[j]) {
          f[pos] = 1;
          break;
        } 
      } 
    }
  }
  for (int i = 1; i <= n; ++i) {
    putchar(f[i] ? 'A' : 'B');
  }
  puts("");
  return 0;
}