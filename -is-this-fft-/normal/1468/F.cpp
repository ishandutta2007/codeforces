#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int gcd (int p, int q) {
  if (p < 0) p *= -1;
  if (q < 0) q *= -1;
  if (q == 0) return p;
  return gcd(q, p % q);
}

typedef pair<int, int> Vec;
#define x first
#define y second

Vec neg (Vec v) {
  return Vec(-v.x, -v.y);
}

void solve () {
  int n;
  cin >> n;

  map<Vec, ll> cnt;
  for (int i = 0; i < n; i++) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;

    int dx = u - x;
    int dy = v - y;
    int gc = gcd(dx, dy);
    dx /= gc;
    dy /= gc;

    cnt[Vec(dx, dy)]++;
  }

  ll ans = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    auto vec = it->first;
    auto nvec = neg(vec);
    if (cnt.count(nvec)) {
      ans += it->second * cnt.at(nvec);
    }
  }
  cout << ans / 2 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}