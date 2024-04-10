#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int a[maxN];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    auto check = [&](int col) {
      vector <int> seq;
      for (int i = 1; i <= n; i++) {
        if (a[i] != col) {
          seq.push_back(a[i]);
        }
      }
      int l = 0, r = (int)seq.size() - 1;
      while (l < r) {
        if (seq[l] != seq[r]) {
          return 0;
        }
        ++l; --r;
      }
      return 1;
    };
    int l = 1, r = n, ans = 1;
    while (l < r) {
      if (a[l] != a[r]) {
        ans = check(a[l]) | check(a[r]);
        break;
      }
      ++l; --r;
    }
    printf("%s\n", ans ? "YES" : "NO");
  }
  return 0;
}