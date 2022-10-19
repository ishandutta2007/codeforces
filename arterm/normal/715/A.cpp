#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 107;

ll n;

void read() {
  cin >> n;
}

void kill() {
  ll cur = 2;
  for (ll k = 1; k <= n; ++k) {
    ll p = k * (k + 1) * (k + 1);
    assert(cur <= p);
    cout << p - cur << "\n";
    cur = k;
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}