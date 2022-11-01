#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 707;

vector <int> g[N];
int n, a[N], f[N][N][2];

int call (int l, int r, int isLeft) {
  if (l > r) return 1;
  int &ret = f[l][r][isLeft];
  if (ret != -1) return ret;
  int par = isLeft ? r + 1 : l - 1;
  ret = 0;
  for (int child : g[par]) {
    if (child >= l and child <= r and call(l, child - 1, 1) and call(child + 1, r, 0)) {  
      ret = 1;
      break;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j and __gcd(a[i], a[j]) > 1) {
        g[i].push_back(j);
      }
    }
  }
  memset(f, -1, sizeof f);
  for (int i = 1; i <= n; ++i) {
    if (call(1, i - 1, 1) and call(i + 1, n, 0)) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}