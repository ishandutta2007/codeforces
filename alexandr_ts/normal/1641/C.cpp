#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 2e6 + 10;

ll t[N], ad[N];

void push(ll v, ll tl, ll tr) {
    if (ad[v] == INF)
        return;
    if (tl == tr) {
        t[v] = ad[v] * (tr - tl + 1);
        ad[v] = INF;
        return;
    }
    t[v] = ad[v] * (tr - tl + 1);
    ad[2 * v] = ad[2 * v + 1] = ad[v];
    ad[v] = INF;
    return;
}

void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = 1;
        return;
    }
    ll tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x) {
    push(v, tl, tr);
    if (tl > r || l > tr)
        return;
    if (l <= tl && tr <= r) {
        ad[v] = x;
        push(v, tl, tr);
        return;
    }
    ll tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, r, x);
    update(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

ll getSum(ll v, ll tl, ll tr, ll l, ll r) {
    push(v, tl, tr);
    if (tl > r || l > tr)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    ll tm = (tl + tr) / 2;
    return getSum(2 * v, tl, tm, l, r) + getSum(2 * v + 1, tm + 1, tr, l, r);
}

int get_left(int v, int tl, int tr, int pos) {
  push(v, tl, tr);
  if (tl == tr) {
    if (t[v] == 1 && pos != tl) {
      return tl;
    }
    return -INF;
  }
  if (t[v] == 0) {
    return -INF;
  }
  if (tl <= pos && pos <= tr && t[v] == 1) {
    return -INF;
  }
  int tm = (tl + tr) / 2;
  int ans = -INF;
  if (tm + 1 < pos) {
    ans = get_left(2 * v + 1, tm + 1, tr, pos);
  }
  if (ans != -INF) {
    return ans;
  }
  return get_left(2 * v, tl, tm, pos);
}

int get_right(int v, int tl, int tr, int pos) {
  push(v, tl, tr);
  if (tl == tr && pos != tl) {
    if (t[v] == 1) {
      return tl;
    }
    return INF;
  }
  if (t[v] == 0) {
    return INF;
  }
  if (tl <= pos && pos <= tr && t[v] == 1) {
    return INF;
  }
  int tm = (tl + tr) / 2;
  int ans = INF;

  if (pos < tm) {
    ans = get_right(2 * v, tl, tm, pos);
  }
  if (ans != INF) {
    return ans;
  }
  return get_right(2 * v + 1, tm + 1, tr, pos);
}

class Solver {
public:

  void solve() {
    int n, q;
    cin >> n >> q;

    fill(ad, ad + 4 * n, INF);
    build(1, 0, n - 1);

    set<pair<int, int>> segs;

    while (q--) {
      int typ;
      cin >> typ;
      //for (auto s : segs) cout << s.first << "-" << s.second << ", ";cout << endl;
      if (typ == 0) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        if (x == 0) {
          update(1, 0, n - 1, l, r, 0);
        } else {
          auto it = segs.lower_bound({l, r});
          if (it != segs.end() && it->second <= r) {
            continue;
          }
          if (it != segs.begin() && prev(it)->first == l) {
            continue;
          }
          it = segs.insert({l, r}).first;
          while (it != segs.begin() && prev(it)->second >= r) {
            segs.erase(prev(it));
          }
          while (next(it) != segs.end() && next(it)->first == l) {
            segs.erase(next(it));
          }
        }
      } else {
        int pos;
        cin >> pos;
        pos--;
        if (getSum(1, 0, n - 1, pos, pos) == 0) {
          cout << "NO\n";
          continue;
        }
        int l = max(-1, get_left(1, 0, n - 1, pos));
        int r = min(n, get_right(1, 0, n - 1, pos));
        //cout << l << " " << r << endl;
        auto it = segs.lower_bound({l + 1, -1});
        if (it != segs.end() && it->second < r) {
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
      }
    }
  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    Solver{}.solve();
  }
}