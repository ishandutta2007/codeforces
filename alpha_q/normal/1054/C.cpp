#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 1010;

bitset <N> done;
int n, a[N], l[N], r[N], ll[N], rr[N], lt[N], rt[N], tot;

bool check() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (a[j] > a[i]) --lt[i];
    }
    for (int j = i + 1; j <= n; ++j) {
      if (a[j] > a[i]) --rt[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (lt[i] != 0) return 0;
    if (rt[i] != 0) return 0;
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", l + i);
    if (l[i] > i - 1) {
      puts("NO");
      return 0;
    }
    lt[i] = ll[i] = l[i];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", r + i);
    if (r[i] > n - i) {
      puts("NO");
      return 0;
    }
    rt[i] = rr[i] = r[i];
  }
  for (int it = n; it >= 1 and tot < n; --it) {
    int cnt = 0;
    // cout << it << endl;
    // for (int i = 1; i <= n; ++i) {
    //   cout << l[i] << " " << r[i] << endl;
    // }
    for (int i = 1; i <= n; ++i) {
      if (done[i]) continue;
      if (l[i] == 0 and r[i] == 0) {
        ++cnt;
      } else {
        if (ll[i] < cnt) {
          puts("NO");
          return 0;
        }
        ll[i] -= cnt;
      }
    }
    cnt = 0;
    for (int i = n; i >= 1; --i) {
      if (done[i]) continue;
      if (l[i] == 0 and r[i] == 0) {
        a[i] = it, done[i] = 1, ++cnt, ++tot;
      } else {
        if (rr[i] < cnt) {
          puts("NO");
          return 0;
        }
        rr[i] -= cnt;
      }
    }
    if (cnt == 0) {
      puts("NO");
      return 0;
    }
    for (int i = 1; i <= n; ++i) {
      l[i] = ll[i], r[i] = rr[i];
    }
  }
  if (tot < n) {
    puts("NO");
    return 0;
  }
  assert(check());
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
  return 0;
}