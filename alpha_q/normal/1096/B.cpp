#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

int n; char s[N];

int main() {
  scanf("%d %s", &n, s + 1);
  int st = 1, en = n;
  while (s[st + 1] == s[1]) ++st;
  while (s[en - 1] == s[n]) --en;
  en = n - en + 1;
  if (s[1] != s[n]) {
    int ans = st + 1 + en;
    ans %= MOD; 
    printf("%d\n", ans);
    return 0;
  }
  long long ans = (st + 1LL) * 1LL * (en + 1LL) % MOD;
  printf("%lld\n", ans);
  return 0;
}