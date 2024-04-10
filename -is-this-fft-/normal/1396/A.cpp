#include <iostream>

using namespace std;

typedef long long ll;

pair<ll, ll> bezout (ll a, ll b) {
  if(b == 0)
    return make_pair(1, 0);
  pair<ll, ll> ret = bezout (b, a%b);
  return {ret.second, ret.first - a/b * ret.second};
}

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] *= -1LL;
  }

  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << arr[1] << endl;

    cout << 1 << " " << 1 << endl;
    cout << arr[1] << endl;

    cout << 1 << " " << 1 << endl;
    cout << -arr[1] << endl;
  } else {
    auto pr = bezout(n, n - 1);
    ll u = pr.first;
    ll v = pr.second;

    cout << 1 << " " << n << endl;
    for (int i = 1; i <= n; i++) {
      cout << u * n * arr[i] << " ";
    }
    cout << endl;

    cout << 2 << " " << n << endl;
    for (int i = 2; i <= n; i++) {
      cout << v * (n - 1) * arr[i] << " ";
    }
    cout << endl;

    cout << 1 << " " << 1 << endl;
    cout << arr[1] - u * n * arr[1] << endl;
  }
}