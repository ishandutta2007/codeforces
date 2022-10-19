#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<ll> times(n);
  vector<ll> timesum(n+1);
  vector<ll> xpos(n, 1e9);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll y;
    int active;
    cin >> xpos[i] >> y >> active;
    int j = upper_bound(xpos.begin(), xpos.end(), y) - xpos.begin();
    times[i] = (xpos[i] - y + timesum[i] - timesum[j]) % MOD;
    timesum[i+1] = (timesum[i] + times[i]) % MOD;
    if (active) {
      ans += times[i];
      ans %= MOD;
    }
  }
  ans = (ans+xpos[n-1]+1+MOD)%MOD;
  cout << ans << endl;
}