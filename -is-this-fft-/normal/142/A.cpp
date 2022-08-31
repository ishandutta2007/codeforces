#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

ll mn, mx;

void solve (ll a, ll b, ll c) {
  ll vol = (a + 1) * (b + 2) * (c + 2);
  mn = min(mn, vol);
  mx = max(mx, vol);
}

void solve (ll a, ll b) {
  for (ll d = 1; d * d <= b; d++) {
    if (b % d == 0) {
      solve(a, d, b / d);
      solve(a, b / d, d);
    }
  }
}

void solve (ll a) {
  for (ll d = 1; d * d <= a; d++) {
    if (a % d == 0) {
      solve(d, a / d);
      solve(a / d, d);
    }
  }
}

int main () {
  int n;
  cin >> n;

  mn = INF;

  solve(n);

  cout << mn - n << " " << mx - n << '\n';
}