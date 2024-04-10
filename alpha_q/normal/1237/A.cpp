#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], add[N];

int main() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    if (a[i] % 2 == 0) a[i] /= 2;
    else {
      if (a[i] < 0) a[i] = a[i] / 2 - 1;
      else a[i] = a[i] / 2;
      add[i] = 1;
    }
    sum += a[i];
  }
  assert(sum <= 0);
  for (int i = 1; i <= n; ++i) {
    if (add[i] == 0) {
      printf("%d\n", a[i]);
    } else {
      if (sum < 0) ++sum, ++a[i];
      printf("%d\n", a[i]);
    }
  }
  return 0;
}