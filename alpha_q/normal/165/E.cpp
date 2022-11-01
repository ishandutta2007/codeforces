#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 22;
const int MASK = (1 << 22) + 5;

int n, a[MASK], f[MASK];

int main() {
  scanf("%d", &n);
  memset(f, -1, sizeof f);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    f[a[i]] = a[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 1 << N; ++j) {
      if (j & 1 << i) f[j] = max(f[j], f[j ^ 1 << i]);
    }
  }
  int all = (1 << N) - 1;
  for (int i = 0; i < n; ++i) {
    printf("%d ", f[all ^ a[i]]);
  }
  puts("");
  return 0;
}