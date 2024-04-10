#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n; 
char s[N], a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s", &n, s + 1);
    int at = 1;
    while (at <= n and s[at] != '1') ++at;
    for (int i = 1; i < at; ++i) {
      if (s[i] == '0') a[i] = b[i] = '0';
      else a[i] = b[i] = '1';
    }
    if (at <= n) {
      a[at] = '1', b[at] = '0';
      for (int i = at + 1; i <= n; ++i) {
        a[i] = '0', b[i] = s[i];
      }
    }
    a[n + 1] = b[n + 1] = 0;
    puts(a + 1); puts(b + 1);
  }
  return 0;
}