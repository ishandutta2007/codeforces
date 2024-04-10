#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll z(ll k, ll m) {
  // send m lines
  if (m <= k) {
    return (m*(m+1))/2;
  }
  ll d = 2*k-1-m;
  return k*k-(d*(d+1))/2;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll k, x;
    cin >> k >> x;
    ll low = 0;
    ll high = 2*k;
    if (z(k, 2*k-1) <= x) {
      cout << 2*k-1 << '\n';
    }
    else {
      while (low + 1 < high) {
        ll mid = (low+high)/2;
        if (z(k, mid) < x) low = mid;
        else high = mid;
      }
      cout << low+1 << '\n';
    }
  }
}