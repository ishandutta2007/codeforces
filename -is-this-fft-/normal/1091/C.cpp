#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

ll fun (ll n, ll k) {
  ll m = n / k;

  return k * m * (m - 1) / 2 + m;
}

int main () {
  ll n;
  cin >> n;

  set<ll> ans;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ans.insert(fun(n, i));
      ans.insert(fun(n, n / i));
    }
  }

  for (ll x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}