#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n; char s[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s", &n, s + 1);
    int cnt[2] = {0, 0}, at = 0;
    for (int i = 1; i <= n;) {
      int j = i, len = 0;
      while (j <= n and s[j] == s[i]) ++j, ++len;
      cnt[at] += len - 1; at ^= 1; i = j;
    }
    printf("%d\n", max(cnt[0], cnt[1]));
  }
  return 0;
}