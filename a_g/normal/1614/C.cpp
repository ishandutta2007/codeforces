#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int base = 0;
    for (int i = 0; i < m; i++) {
      int l, r, x;
      cin >> l >> r >> x;
      base |= x;
    }
    cout << expmod(2, n-1, MOD)*(base % MOD) % MOD << '\n';
  }
}