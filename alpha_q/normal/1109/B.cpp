#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n; char s[N];

bool eq (int l) {
  for (int i = 1, j = l; i <= n; ++i, ++j) {
    if (s[i] != s[j]) return 0;
  } return 1;
}

bool pal (int l) {
  for (int i = l, j = l + n - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return 0;
  } return 1;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) s[n + i] = s[i];

  int bad = 1;
  for (int i = 1, j = n; i < j; ++i, --j) {
    if (s[i] != s[1]) {
      bad = 0; break;
    }
  }

  if (bad) {
    puts("Impossible");
    return 0;
  }

  if (~n & 1) {
    for (int i = 1; i <= n; ++i) {
      if (!eq(i) and pal(i)) {
        puts("1"); return 0;
      }
    }
  }

  puts("2");
  return 0;
}