#include <iostream>

using namespace std;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

const int MAX_LG = 30;

// greatest n s.t. 2n^2 <= m
ll gsq (ll m) {
  ll ans = 0;
  for (ll k = 1LL << MAX_LG; k != 0; k /= 2) {
    ll cur = ans + k;
    if (sq(cur) + sq(cur) <= m) {
      ans += k;
    }
  }
  return ans;
}

// greatest n s.t. n^2 + (n + 1)^2 <= m
ll gsqp (ll m) {
  ll ans = 0;
  for (ll k = 1LL << MAX_LG; k != 0; k /= 2) {
    ll cur = ans + k;
    if (sq(cur) + sq(cur + 1) <= m) {
      ans += k;
    }
  }
  return ans;
}

void solve () {
  ll D, K;
  cin >> D >> K;

  ll amax = gsq(sq(D) / sq(K));
  ll bmax = gsqp(sq(D) / sq(K));

  if (amax <= bmax) {
    cout << "Ashish" << '\n';
  } else {
    cout << "Utkarsh" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}