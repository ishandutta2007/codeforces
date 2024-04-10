#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll cb (ll x) {
  return x * x * x;
}

pair<bool, ll> l_cbrt (ll x) {
  ll cans = (ll) pow(x, 1.0/3.0) - 2;
  for (int i = 0; i < 5; i++) {
    if (cb(cans + i) == x) {
      return make_pair(true, cans + i);
    }
  }
  return make_pair(false, 0);
}

bool solve (ll a, ll b) {
  pair<bool, ll> cbr = l_cbrt(a * b);

  if (!cbr.first) return false;
  ll p = cbr.second;
  if (a % p != 0) return false;
  if (b % p != 0) return false;
  return true;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    int a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? "Yes" : "No") << '\n';
  }
}