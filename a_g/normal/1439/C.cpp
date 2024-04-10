#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class segtree {
  public:
    vector<int> lazy;
    vector<ll> segsum;
    vector<int> leftpt;
    vector<int> rightpt;
    int n;
    segtree (vector<int>& a) {
      n = a.size();
      lazy.resize(4*n, 0);
      segsum.resize(4*n, 0);
      leftpt.resize(4*n, 0);
      rightpt.resize(4*n, 0);
      init(0, 0, n-1, a);
    }

    void init(int v, int tl, int tr, vector<int>& a) {
      if (tl == tr) {
        lazy[v] = a[tl];
        return;
      }
      int tm = (tl+tr)/2;
      init(2*v+1, tl, tm, a);
      init(2*v+2, tm+1, tr, a);
      combine(v, tl, tr);
    }

    void push(int v) {
      lazy[2*v+1] = max(lazy[v], lazy[2*v+1]);
      lazy[2*v+2] = max(lazy[v], lazy[2*v+2]);
      lazy[v] = 0;
    }

    void apply_max(int m, int i) {
      apply_max(0, 0, n-1, m, i);
    }
    void apply_max(int v, int tl, int tr, int m, int i) {
      if (tl > i || realrightpt(v) >= m) return;
      if (tl == tr) {
        lazy[v] = m;
        return;
      }
      if (realleftpt(v) <= m && tr <= i) {
        lazy[v] = m;
        return;
      }
      push(v);
      int tm = (tl+tr)/2;
      apply_max(2*v+1, tl, tm, m, i);
      apply_max(2*v+2, tm+1, tr, m, i);
      combine(v, tl, tr);
    }

    pair<int, int> query(int i, int x) {
      // first: how many meals are eaten
      // second: total cost of those meals
      return query(0, 0, n-1, i, x);
    }
    pair<int, int> query(int v, int tl, int tr, int i, int x) {
      if (tr < i || realrightpt(v) > x) return {0, 0};
      if (realsegsum(v, tl, tr) <= x && tl >= i) return {tr-tl+1, realsegsum(v, tl, tr)};
      push(v);
      int tm = (tl+tr)/2;
      pair<int, int> lquery = query(2*v+1, tl, tm, i, x);
      x -= lquery.second;
      pair<int, int> rquery = query(2*v+2, tm+1, tr, i, x);
      combine(v, tl, tr);
      return {lquery.first+rquery.first, lquery.second+rquery.second};
    }

    int realleftpt(int v) {
      return max(leftpt[v], lazy[v]);
    }
    int realrightpt(int v) {
      return max(rightpt[v], lazy[v]);
    }
    ll realsegsum(int v, int tl, int tr) {
      if (lazy[v]) return 1LL*(tr-tl+1)*lazy[v];
      return segsum[v];
    }

    void combine(int v, int tl, int tr) {
      leftpt[v] = realleftpt(2*v+1);
      rightpt[v] = realrightpt(2*v+2);
      int tm = (tl+tr)/2;
      segsum[v] = realsegsum(2*v+1, tl, tm) + realsegsum(2*v+2, tm+1, tr);
    }

    void debug(int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << leftpt[v] << " " << rightpt[v] << " " << segsum[v] << " " << lazy[v] << '\n';
      if (tl != tr) {
        int tm = (tl+tr)/2;
        debug(2*v+1, tl, tm);
        debug(2*v+2, tm+1, tr);
      }
    }
    void debug() {
      debug(0, 0, n-1);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  segtree st(a);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      st.apply_max(y, x-1);
    }
    else {
      cout << st.query(x-1, y).first << '\n';
    }
  }
}