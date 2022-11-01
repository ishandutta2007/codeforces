#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int ex;
char s[N], t[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), sz = 0;
  for (int l = 1, r = n; l <= r;) {
    if (l == r) {
      ex = 1;
      t[++sz] = s[l];
      break;
    }
    if (s[l] == s[r]) {
      t[++sz] = s[l];
      ++l, --r;
    } else {
      if (s[l + 1] == s[r]) {
        ++l; continue;
      }
      if (s[r - 1] == s[l]) {
        --r; continue;
      }
      assert(s[l + 1] == s[r - 1]);
      ++l, --r;
    }
  }
  for (int i = 1; i <= sz; ++i) putchar(t[i]);
  for (int i = sz - ex; i >= 1; --i) putchar(t[i]);
  puts("");
  int tot = sz + sz - ex;
  assert(tot >= n / 2);
  return 0;
}