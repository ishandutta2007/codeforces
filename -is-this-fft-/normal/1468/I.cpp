#include <iostream>

using namespace std;

typedef long long ll;

#define x first
#define y second

ll floor (ll p, ll q);

ll ceil (ll p, ll q) {
  if (p < 0) {
    return -floor(-p, q);
  }
  return (p + q - 1) / q;
}

ll floor (ll p, ll q) {
  if (p < 0) {
    return -ceil(-p, q);
  }
  return p / q;
}

int main () {
  int n;
  cin >> n;

  pair<ll, ll> u, v;
  cin >> u.x >> u.y >> v.x >> v.y;

  if (u.y < 0) {
    u.x *= -1;
    u.y *= -1;
  }

  if (v.y < 0) {
    v.x *= -1;
    v.y *= -1;
  }

  ll area = u.x * v.y - v.x * u.y;
  if (area > 0) {
    swap(u, v);
  } else {
    area *= -1;
  }
  
  if (area != n) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  for (ll y = 0; y < u.y + v.y; y++) {
    bool lmd = y < u.y;
    ll l;
    if (lmd) {
      l = ceil(y * u.x, u.y);
    } else {
      l = u.x + ceil((y - u.y) * v.x + 1, v.y);
    }

    bool rmd = y < v.y;
    ll r;
    if (rmd) {
      r = floor(y * v.x, v.y);
    } else {
      r = v.x + floor((y - v.y) * u.x - 1, u.y);
    }

    for (ll x = l; x <= r; x++) {
      cout << x << " " << y << '\n';
    }
  }
}