#include <bits/stdc++.h> 

using namespace std;
 
// 1 + 2 = 3 
// baab ---> babba ---> bbbbbaa

const int N = 1000010;
const int MOD = 1e9 + 7;

char s[N];
long long ans, carry;

int main (int argc, char const *argv[]) {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  int start = n; 
  while (start and s[start] == 'a') {
    --start;
  }
  for (int i = start; i > 0; --i) {
    long long tot = carry;
    while (i and s[i] == 'b') {
      --i, ++tot;
    }
    if (i <= 0) break;
    tot %= MOD;
    carry = (tot * 2ll) % MOD;
    ans += tot;
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}