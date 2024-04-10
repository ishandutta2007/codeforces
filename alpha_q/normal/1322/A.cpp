#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
char s[N];

int main() {
  scanf("%d %s", &n, s);
  int del = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '(') ++del; else --del;
  }
  if (del) {
    puts("-1");
    return 0;
  }
  int ans = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] == '(') ++del; else --del;
    if (del == -1) {
      int j = i + 1, cur = -1;
      while (s[j] and cur < 0) {
        if (s[j] == '(') ++cur; else --cur; ++j;
      }
      // cout << i << " " << j << endl;
      ans += j - i; i = j - 1; del = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}