#include <iostream>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 15;

ll sq (ll x) {
  return x * x;
}

void printx (int cnt) {
  for (int i = 0; i < cnt; i++) {
    cout << 'x';
  }
}

void printo (int cnt) {
  for (int i = 0; i < cnt; i++) {
    cout << 'o';
  }
}

int main () {
  ll a, b;
  cin >> a >> b;

  if (a == 0) {
    cout << -sq(b) << endl;
    printx(b);
    cout << endl;
    return 0;
  }

  if (b <= 1) {
    cout << sq(a) - sq(b) << endl;
    printo(a);
    printx(b);
    cout << endl;
    return 0;
  }

  pair<ll, ll> ans = make_pair(-INF, -1);
  for (ll k = 1; k <= a && k + 1 <= b; k++) {
    ll bssz = b / (k + 1); // the small one
    ll bbcnt = b % (k + 1);
    ll bscnt = k + 1 - bbcnt;

    ll cur = -bscnt * sq(bssz) + -bbcnt * sq(bssz + 1) + (k - 1) + sq(a - k + 1);
    ans = max(ans, make_pair(cur, k));
  }

  cout << ans.first << endl;

  ll K = ans.second;
  ll bssz = b / (K + 1);
  ll bbcnt = b % (K + 1);

  for (int i = 0; i <= K; i++) {
    if (i >= bbcnt) {
      printx(bssz);
    } else {
      printx(bssz + 1);
    }
    
    if (i == K) {
      break; // no o-s
    }

    if (i == 0) {
      printo(a - K + 1);
    } else {
      printo(1);
    }
  }
  cout << endl;
}