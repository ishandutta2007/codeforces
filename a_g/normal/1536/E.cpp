#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    ll c = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      c += count(s.begin(), s.end(), '#');
    }
    ll ans = expmod(2, c, MOD);
    if (c == n*m) ans--;
    cout << ans << endl;
  }
}