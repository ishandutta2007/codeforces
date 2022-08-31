#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> powers (ll x) {
  ll cur = 1;
  vector<ll> ans;
  while (true) {
    ans.push_back(cur);
    ll tg;
    if (__builtin_mul_overflow(cur, x, &tg)) {
      return ans;
    }
    cur = tg;
  }
}

int main () {
  ios::sync_with_stdio(false);

  ll x, y, L, R;
  cin >> x >> y >> L >> R;

  vector<ll> xp = powers(x);
  vector<ll> yp = powers(y);

  set<ll> unlucky;
  for (auto xpp : xp) {
    for (auto ypp : yp) {
      ll cur;
      if (!__builtin_add_overflow(xpp, ypp, &cur)) {
        unlucky.insert(cur);
      }
    }
  }

  ll cur = L;
  ll ans = 0;
  while (true) {
    if (!unlucky.count(cur)) {
      auto nxtp = unlucky.lower_bound(cur);
      ll nxt;
      if (nxtp == unlucky.end()) {
        nxt = R + 1;
      } else {
        nxt = *nxtp;
      }
      nxt = min(nxt, R + 1);

      //  cerr << cur << " " << nxt << endl;
    
      ans = max(ans, nxt - cur);
      if (nxt == R + 1) break;
      cur = nxt + 1;
    } else {
      cur++;
      if (cur > R) break;
    }
  }

  cout << ans << endl;
}