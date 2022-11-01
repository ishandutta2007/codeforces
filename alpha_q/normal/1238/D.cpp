#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

char s[N];
int n, m, a[N]; 

int main() {
  scanf("%d %s", &n, s + 1);
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n and s[j] == s[i]) ++j;
    a[++m] = j - i, i = j;
  }
  long long ans = n * 1LL * (n + 1) / 2 - n;
  for (int i = 1; i < m; ++i) {
    int x = a[i], y = a[i + 1];
    ans -= x, ans -= y, ++ans;
  }
  cout << ans << '\n';
  return 0;
}