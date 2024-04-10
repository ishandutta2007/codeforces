#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;
ll n, k, s[N];
void solve() {
  cin >> n >> k;
  for(int i = 1; i <= k; i++) cin >> s[i];
  if(k == 1) return puts("YES"), void();
  for(int i = 2; i < k; i++)
    if(s[i] - s[i - 1] > s[i + 1] - s[i])
      return puts("NO"), void();
  ll lst = s[2] - s[1];
  if(lst * (n - k + 1) < s[1]) puts("NO");
  else puts("YES");
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}