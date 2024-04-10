#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 5;
int n, q, a[N], d[8];
ll f[8][N];
multiset<ll> s;
void solve() {
  s.clear();
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int tmp = n, cnt = 0;
  for(int i = 2; i <= tmp; i++)
    if(tmp % i == 0) {
      d[++cnt] = n / i;
      while(tmp % i == 0) tmp /= i;
    }
  for(int i = 1; i <= cnt; i++) {
    for(int j = 0; j < d[i]; j++) f[i][j] = 0;
    for(int j = 1; j <= n; j++) f[i][j % d[i]] += a[j];
    for(int j = 0; j < d[i]; j++) s.insert(d[i] * f[i][j]);
  }
  cout << *s.rbegin() << "\n";
  for(int i = 1; i <= q; i++) {
    int p, x;
    cin >> p >> x;
    for(int j = 1; j <= cnt; j++) {
      s.erase(s.find(d[j] * f[j][p % d[j]]));
      f[j][p % d[j]] += x - a[p];
      s.insert(d[j] * f[j][p % d[j]]);
    }
    cout << *s.rbegin() << "\n";
    a[p] = x;
  }
}
int main() {
  ios::sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while(T--) solve();
  return 0;
}