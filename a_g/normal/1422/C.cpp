#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int maxn = 1e5+7;
int p10[maxn];
int c2[maxn];
int d[maxn];
int l[maxn];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  p10[0] = 1;
  for (int i = 1; i < maxn; i++) {
    p10[i] = 10LL * p10[i-1]  % MOD;
    c2[i] = (c2[i-1] + (i-1)) % MOD;
    l[i] = (l[i-1] + 1LL * p10[i-1]*i) % MOD;
  }
  string s;
  cin >> s;
  int m = s.size();
  int ans = 0;
  for (int i = 0; i < m; i++) {
    d[i] = s[m-1-i] - '0';
    ans += 1LL * d[i] * l[i] % MOD;
    ans %= MOD;
    ans += 1LL * p10[i] * (1LL * c2[m-i] * d[i] % MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}