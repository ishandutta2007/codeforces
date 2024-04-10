#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 200010;

int n;
char s[N];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    s[n + i] = s[i];
  }
  int ans = 1;
  for (int i = 1; i <= n;) {
    int j = i;
    while (j < n + i - 1 and s[j + 1] != s[j]) {
      ++j;
    }
    ans = max(ans, j - i + 1);
    i = j + 1;
  }
  printf("%d\n", ans);
  return 0;
}