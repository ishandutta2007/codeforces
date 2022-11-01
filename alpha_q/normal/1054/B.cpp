#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;

int n, a[N], ya[N], f[N];

void update (int p) {
  ++p;
  while (p < N) {
    f[p] += 1, p += p & -p;
  }
}

int get (int p) {
  ++p; 
  int ret = 0;
  while (p > 0) {
    ret += f[p], p -= p & -p;
  }
  return ret;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 0) {
      if (!ya[0]) {
        ya[0] = 1;
        update(0);
      }
      continue;
    }
    if (a[i] > 100000) {
      printf("%d\n", i);
      return 0;
    }
    if (get(a[i] - 1) != a[i]) {
      printf("%d\n", i);
      return 0;
    }
    if (!ya[a[i]]) {
      ya[a[i]] = 1;
      update(a[i]);
    }
  }
  puts("-1");
  return 0;
}