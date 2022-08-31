#include <iostream>

using namespace std;

typedef long long ll;

ll solve (ll i, ll n) {
  if (i % 2 == 1) {
    return (i + 1) / 2;
  } else {
    return solve(n + i / 2, n);
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  ll n;
  int q;
  cin >> n >> q;

  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    cout << solve(x, n) << '\n';
  }
}