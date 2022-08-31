#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_A = 1e9 + 5;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll lcm (ll p, ll q) {
  return (p / gcd(p, q)) * q;
}

void solve () {
  int n;
  cin >> n;

  bool ok = true;
  ll prod = 1;
  for (int i = 2; i <= n + 1; i++) {
    int x;
    cin >> x;

    if (prod < MAX_A) {
      prod = lcm(i, prod);
    }

    if (x % prod == 0) {
      ok = false;
    }
  }

  if (ok) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}