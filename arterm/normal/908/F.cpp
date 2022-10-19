#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const ll inf = 1e10;

ll b = -inf, r = -inf, g = -inf;
ll minb = inf, minr = inf, ming = inf;
ll maxb = -inf, maxr = -inf, maxg = -inf;

int n;
ll diff = 0;

void read() {
  cin >> n;
}

void kill() {
  ll bestr = 0, bestb = 0;
  for (int i = 0; i < n; ++i) {
    char c;
    ll x;
    cin >> x >> c;

    if (c == 'G') {
      ming = min(ming, x);
      maxg = max(maxg, x);

      if (g != -inf) {
        bestr = max(bestr, x - max(g, r));
        bestb = max(bestb, x - max(g, b));
        ll dist = x - g;
        if (bestr + bestb >= dist)
          diff += dist - bestr - bestb;
      }
      bestr = bestb = 0;
      g = x;
    }

    if (c == 'R') {
      minr = min(minr, x);
      maxr = max(maxr, x);

      bestr = max(bestr, x - max(g, r));
      r = x;
    }

    if (c == 'B') {
      minb = min(minb, x);
      maxb = max(maxb, x);
      bestb = max(bestb, x - max(g, b));
      b = x;
    }
  }

  diff += max(0ll, max(maxb, maxg) - min(minb, ming));
  diff += max(0ll, max(maxr, maxg) - min(minr, ming));

  cout << diff << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
#ifdef LOCAL
  freopen("f.in", "r", stdin);
#endif

  read();
  kill();
    
  return 0;
}