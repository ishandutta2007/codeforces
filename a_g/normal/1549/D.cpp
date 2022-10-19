#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long gcd(long long a, long long b) {
  if (b < 0) {
    return gcd(a, -b);
  }
  if (a < b) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(a-(a/b)*b, b);
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n-1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n-1; i++) {
      d[i] = a[i+1]-a[i];
    }
    int COL = 20;
    vector<vector<ll>> gcdtable(COL, vector<ll>(n-1, 0));
    gcdtable[0] = d;
    for (int i = 1; i < COL; i++) {
      ll x = 1 << (i-1);
      for (int j = 0; j < n-2*x; j++) {
        gcdtable[i][j] = gcd(gcdtable[i-1][j], gcdtable[i-1][j+x]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
      int start = i;
      ll g = 0;
      int p = 20;
      ll x = 1 << p;
      while (p > -1) {
        if (start + x <= n-1) {
          //cout << start << " " << x << endl;
          ll h = gcdtable[p][start];
          // cout << g << " " << h << endl;
          if (gcd(g, h) > 1) {
            start += x;
            g = gcd(g, h);
          }
        }
        x = x/2;
        p--;
      }
      //cout << i << " " << start-i << endl;
      ans = max(ans, start-i);
    }
    cout << ans+1 << endl;
  }
}