#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

pair<ll, ll> ext_euclid (ll a, ll b) {
  if (b == 0)
    return make_pair(1, 0);
  pair<int, int> ret = ext_euclid(b, a % b);
  return {ret.second, ret.first - a/b * ret.second};
}


ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll lcm (ll p, ll q) {
  return (p / gcd(p, q)) * q;
}

const int MAX_N = 5e5 + 5;
const int MAX_A = 1e6 + 5;

int inA [MAX_A], inB [MAX_A];

int main () {
  for (int i = 0; i < MAX_A; i++) {
    inA[i] = -1;
    inB[i] = -1;
  }
  
  ios::sync_with_stdio(false);

  int n, m;
  ll K;
  cin >> n >> m >> K;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    inA[x] = i;
  }

  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;

    inB[y] = i;
  }

  ll gc = gcd(n, m), lc = lcm(n, m);
  auto uv = ext_euclid(n, m);
  set<ll> matches;
  for (int i = 0; i < MAX_A; i++) {
    if (inA[i] != -1 && inB[i] != -1) {
      if (inA[i] % gc != inB[i] % gc) {
        continue;
      }

      ll mat = ((ll) inA[i] * ((ll) m / gc) * uv.second + (ll) inB[i] * ((ll) n / gc) * uv.first) % lc;
      if (mat < 0) {
        mat += lc;
      }
      matches.insert(mat);
    }
  }


  ll misses = lc - matches.size(); // misses per cycle
  ll left = K % misses;
  if (left == 0) {
    left += misses;
  }
  ll ans = ((K - left) / misses) * lc;

  matches.insert(lc);
  ll cur = 0;
  while (true) {
    while (matches.count(cur)) {
      cur++;
    }

    auto nxt = *matches.upper_bound(cur);
    if (nxt - cur < left) {
      left -= nxt - cur;
      cur = nxt;
    } else {
      ans += cur + left;
      break;
    }
  }

  cout << ans << '\n';
}