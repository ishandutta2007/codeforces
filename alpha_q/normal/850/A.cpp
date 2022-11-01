#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N][7];
vector <int> idx;

int dot (int o, int i, int j) {
  int res = 0;
  for (int k = 0; k < 5; ++k) {
    res += (a[i][k] - a[o][k]) * (a[j][k] - a[o][k]);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 5; ++j) {
      scanf("%d", a[i] + j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    int good = 1;
    for (int j = 1; j <= n; ++j) {
      if (j == i) continue;
      for (int k = 1; k <= n; ++k) {
        if (k == i or k == j) continue;
        if (dot(i, j, k) > 0) {
          good = 0;
          break;
        }
      }
      if (good == 0) break;
    }
    if (good) {
      idx.push_back(i);
    }
  }
  printf("%d\n", (int) idx.size());
  for (int x : idx) printf("%d\n", x);
  return 0;
}