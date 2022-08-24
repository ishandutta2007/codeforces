#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1e6 + 228;

vector <pair <int, int> > op[N], cl[N];
ll add[N];

ll t[4 * N];
ll cost[4 * N];

void upd(int v, int l, int r, int i, int x) {
  if (r - l == 1) {
    t[v] += x;
    cost[v] += x * (ll) l;
  } else {
    int m = (l + r) / 2;
    if (i < m) {
      upd(v * 2 + 1, l, m, i, x);
    } else {
      upd(v * 2 + 2, m, r, i, x);
    }
    cost[v] = cost[v * 2 + 1] + cost[v * 2 + 2];
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
  }
}

ll s(int v, int l, int r, int k) {
  if (r - l == 1) {
    return l;
  } else {
    int m = (l + r) / 2;
    if (t[v * 2 + 1] >= k) {
      return s(v * 2 + 1, l, m, k);
    } else {
      return s(v * 2 + 2, m, r, k - t[v * 2 + 1]);
    }
  }
}

ll kek = 0;

ll get(int v, int l, int r, int tl, int tr) {
  if (tl >= r || tr <= l) {
    return 0;
  }
  if (tl >= l && tr <= r) {
    kek += cost[v];
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    return get(v * 2 + 1, l, r, tl, tm) + get(v * 2 + 2, l, r, tm, tr);
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,  k, m;
  cin >> n >> k >> m;
  int mc = (int) (1e6) + 1;
  for (int i = 0; i < m; i++) {
    int l, r, c, p;
    cin >> l >> r >> c >> p;
    op[l].push_back({p, c});
    op[r + 1].push_back({p, -c});
  }
  ll was = 0;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (auto c : op[i]) {
      upd(0, 0, mc, c.first, c.second);
    }
    if (op[i].empty()) {
      ans += was;
    } else {
      was = 0;
      if (t[0] <= k) {
        was += cost[0];
      } else {
        kek = 0;
        int op = s(0, 0, mc, k);
        ll m = get(0, 0, op, 0, mc);
        was += kek;
        was += op * (ll) (k - m);
      }
      ans += was;
    }
  }
  cout << ans << endl;
}