#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

struct Interval {
  int L, R;
  int orig_id;

  Interval (int _L = 0, int _R = 0, int _orig_id = -1) : L(_L), R(_R), orig_id(_orig_id) {}
};

class Segtree {
  int n;
  vector<pair<int, int>> tree;
  vector<int> lfend;
  vector<int> rgend;

public:
  Segtree (int _n = 0) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<pair<int, int>> (2 * n, make_pair(0, 0));
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  pair<int, int> query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return make_pair(0, 0);
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return max(query(ql, qr, 2 * u),
               query(ql, qr, 2 * u + 1));
  }

  void update (int u) {
    if (u == 0) return;
    tree[u] = max(tree[2 * u], tree[2 * u + 1]);
    update(u / 2);
  }
  
  void set (int pos, pair<int, int> val) {
    tree[n + pos] = val;
    update((n + pos) / 2);
  }
};

bool cmp (Interval p, Interval q) {
  if (p.L != q.L) {
    return p.L < q.L;
  }

  return p.R > q.R;
}

Interval intersect (Interval p, Interval q) {
  return Interval(max(p.L, q.L), min(q.R, p.R));
}

ll len (Interval p) {
  return max(0, p.R - p.L);
}

int main () {
  int n, m;
  cin >> n >> m;

  vector<Interval> iranges (n);
  for (int i = 0; i < n; i++) {
    cin >> iranges[i].L >> iranges[i].R;
    iranges[i].orig_id = i + 1;
  }

  sort(iranges.begin(), iranges.end(), cmp);

  vector<Interval> ranges;
  int cr = -1;
  for (int i = 0; i < n; i++) {
    if (iranges[i].R > cr) {
      cr = iranges[i].R;
      ranges.push_back(iranges[i]);
    }
  }

  n = ranges.size();
  map<int, int> byl, byr;
  Segtree maxlen (n);
  for (int i = 0; i < n; i++) {
    byl[ranges[i].L] = i;
    byr[ranges[i].R] = i;
    maxlen.set(i, make_pair(len(ranges[i]), ranges[i].orig_id));
  }

  pair<ll, pair<int, int>> ans = make_pair(0LL, make_pair(-1, -1));
  for (int i = 0; i < m; i++) {
    Interval cur;
    cin >> cur.L >> cur.R;
    ll coef;
    cin >> coef;
    
    auto rit = byr.upper_bound(cur.R); // first one that ends after;
    if (rit != byr.end()) {
      ll cans = coef * len(intersect(cur, ranges[rit->second]));
      ans = max(ans, make_pair(cans, make_pair(ranges[rit->second].orig_id, i + 1)));
    }
    
    auto lit = byl.lower_bound(cur.L);
    if (lit != byl.begin()) {
      ll cans = coef * len(intersect(cur, ranges[prev(lit)->second]));
      ans = max(ans, make_pair(cans, make_pair(ranges[prev(lit)->second].orig_id, i + 1)));
    }

    if (rit != byr.begin() && lit != byl.end()) {
      int l = lit->second;
      int r = prev(rit)->second;

      
      if (l <= r) {
        auto qans = maxlen.query(l, r);
        ll cans = coef * qans.first;
        ans = max(ans, make_pair(cans, make_pair(qans.second, i + 1)));
      }
    }
  }

  cout << ans.first << endl;
  if (ans.first > 0) {
    cout << ans.second.first << " " << ans.second.second << endl;
  }
}