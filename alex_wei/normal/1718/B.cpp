////////////////
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 105;
int n, p, c[N], f[N];
long long s[N], z;
void solve() {
  cin >> n, p = z = 0;
  for(int i = 1; i <= n; i++) cin >> c[i], z += c[i];
  if(n >= 45) return puts("NO"), void();
  sort(c + 1, c + n + 1);
  while(p < 43 && s[p + 1] <= z) p++;
  while(~p) {
    c[n] -= f[p--];
    if(c[n] < 0 || c[n] > c[n - 1]) return puts("NO"), void();
    for(int i = n; i > 1; i--) if(c[i] < c[i - 1]) swap(c[i], c[i - 1]);
  }
  puts(c[n] ? "NO" : "YES");
}
int main() {
  f[0] = f[1] = s[0] = 1, s[1] = 2;
  for(int i = 2; i < 44; i++) s[i] = s[i - 1] + (f[i] = f[i - 1] + f[i - 2]);
  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}