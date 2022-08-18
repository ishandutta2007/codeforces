#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int bitlog (ll x) {
  return 64 - __builtin_clzll(x);
}

pair<int, ll> emul (ll x, ll y) {
  if (bitlog(x) + bitlog(y) > 60) return make_pair(-1, 0);
  return make_pair(0, x * y);
}

int main () {
  ios::sync_with_stdio(false);

  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;

  vector<ll> xs (1, x0);
  vector<ll> ys (1, y0);
  while (true) {
    pair<int, ll> nx = emul(xs.back(), ax);
    pair<int, ll> ny = emul(ys.back(), ay);

    if (nx.first < 0 || ny.first < 0) break;
    xs.push_back(nx.second + bx);
    ys.push_back(ny.second + by);
  }

  ll sx, sy, t;
  cin >> sx >> sy >> t;
  
  int ans = 0;
  int n = xs.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      ll dxr = abs(xs[j] - sx) + abs(xs[j] - xs[i]);
      ll dxl = abs(xs[i] - sx) + abs(xs[j] - xs[i]);

      ll dyr = abs(ys[j] - sy) + abs(ys[j] - ys[i]);
      ll dyl = abs(ys[i] - sy) + abs(ys[j] - ys[i]);

      ll curt = min(dxr + dyr, dxl + dyl);
      if (curt <= t) ans = max(ans, j - i + 1);
    }
  }

  cout << ans << endl;
}