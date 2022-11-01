#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n;
long long a[N], b[N];

inline int pre (int i) {
  return i == 1 ? n : i - 1;
}

inline int nxt (int i) {
  return i == n ? 1 : i + 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", b + i);
  }
  bool allEq = 1;
  for (int i = 1; i <= n; ++i) {
    if (b[i] != b[1]) {
      allEq = 0;
      break;
    }
  }
  if (allEq) {
    if (b[1] > 0) {
      puts("NO");
      return 0;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("1 ");
    }
    cout << '\n';
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    if (b[i] < b[nxt(i)]) {
      a[nxt(i)] = b[nxt(i)];
      a[i] = 200000 * a[nxt(i)] + b[i];
      for (int j = pre(i); j != nxt(i); j = pre(j)) {
        a[j] = a[nxt(j)] + b[j];
      }
      for (int j = 1; j <= n; ++j) {
        printf("%lld ", a[j]);
      }
      puts("");
      return 0;
    }
  }
  assert(false);
  return 0;
}