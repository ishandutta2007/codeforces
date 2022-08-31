#include <iostream>
#include <cmath>

typedef long long ll;

#define x first
#define y second

using namespace std;

ll sq (ll x) {
  return x * x;
}

int main () {
  ll r;
  cin >> r;

  if (r == 0) {
    cout << 1 << endl;
    return 0;
  }
  
  ll ans = 0;
  pair<ll, ll> cur = make_pair(0, r);
  while (cur.y != 0) {
    ans++;

    if (sq(cur.x + 1) + sq(cur.y) <= sq(r)) {
      cur.x++;
    } else if (sq(cur.x + 1) + sq(cur.y - 1) <= sq(r)) {
      cur.x++;
      cur.y--;
    } else {
      cur.y--;
    }
  }

  cout << 4 * ans << endl;
}