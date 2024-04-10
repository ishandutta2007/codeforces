#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll val = 0;
    for (int j = 0; j < 2; j++) {
      ll g = 0;
      for (int i = j; i < n; i += 2) {
        g = __gcd(g, a[i]);
      }
      bool good = 1;
      for (int i = 1-j; i < n; i += 2) {
        if (a[i] % g == 0) good = 0;
      }
      if (good) val = g;
    }
    cout << val << '\n';
  }
}