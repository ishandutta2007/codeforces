#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t;
char a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%s %s", a + 1, b + 1);
    int n = strlen(a + 1);
    int m = strlen(b + 1);
    int pos = n, at = m, ans = 0;
    while (b[at] == '0') --at, --pos;
    while (a[pos] == '0') --pos, ++ans;
    printf("%d\n", ans);
  }
  return 0;
}