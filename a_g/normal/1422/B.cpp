#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 103;
ll a[maxn][maxn];

ll f(ll a, ll b, ll c, ll d) {
  ll ans = 1e15;
  for (ll u: {a, b, c, d}) {
    ans = min(ans, abs(u-a)+abs(u-b)+abs(u-c)+abs(u-d));
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    ll ans = 0;
    for (int i = 0; i < n/2; i++) {
      for (int j = 0; j < m/2; j++) {
        ans += f(a[i][j], a[n-1-i][j], a[i][m-1-j], a[n-1-i][m-1-j]);
      }
    }
    if (n & 1) {
      for (int j = 0; j < m/2; j++) {
        ans += abs(a[n/2][j] - a[n/2][m-1-j]);
      }
    }
    if (m & 1) {
      for (int i = 0; i < n/2; i++) {
        ans += abs(a[i][m/2] - a[n-1-i][m/2]);
      }
    }
    cout << ans << '\n';
  }
}