#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll x, y, p, q;

void read() {
    cin >> x >> y >> p >> q;
}

void kill() {
    if (p == q) {
        if (x == y) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
        return;
    }

    if (p == 0) {
        if (x == 0) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
        return;
    }

    ll d = q - p;
    ll A = q * x - p * y;

    ll a = 0;

    if (A < 0) {
        a = (-A + (d - 1)) / d;
    }

    ll rem = (-x) % p;
    if (rem < 0)
        rem += p;

    a = p * ((a - rem + p - 1) / p) + rem;
    assert(a >= 0);
    
    ll b = (A + d * a) / p;
    assert((x + a) * q == p * (y + b + a));
    assert(b >= 0);

    cout << a + b << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
      read();
      kill();
  }

}