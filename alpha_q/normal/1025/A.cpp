#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

char s[100010];
int n, cnt[30];

int main() {
  scanf("%d %s", &n, s + 1);
  char c = s[1];
  int same = 1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] != c) {
      same = 0;
      break;
    }
  }
  if (same) {
    puts("Yes");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  int good = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > 1) {
      good = 1;
      break;
    }
  }
  puts(good ? "Yes" : "No");
  return 0;
}