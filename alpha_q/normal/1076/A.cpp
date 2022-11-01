#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n;
char s[N];

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i < n; ++i) {
    if (s[i] > s[i + 1]) {
      for (int j = 1; j <= n; ++j) {
        if (j == i) continue;
        putchar(s[j]);
      }
      puts("");
      return 0;
    }
  }
  s[n] = 0;
  puts(s + 1);
  return 0;
}