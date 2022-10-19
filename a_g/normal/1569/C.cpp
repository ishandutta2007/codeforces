#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MOD = 998244353;

ll expmod(long long a, long long b, int m) {
  int res = 1;
  a = a % m; 

  if (a == 0) return 0;

  while (b > 0)
  {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int M = 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
      cin >> vals[i];
      M = max(M, vals[i]);
    }
    int bigcount = 0;
    int littlecount = 0;
    for (int i: vals) {
      if (i == M) {
        bigcount++;
      }
      if (i == M-1) {
        littlecount++;
      }
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
      ans *= i;
      ans %= MOD;
    }
    if (bigcount == 1) {
      ans *= littlecount;
      ans %= MOD;
      ans *= expmod(littlecount+bigcount, MOD-2, MOD);
      ans %= MOD;
    }
    cout << ans << endl;
  }
}