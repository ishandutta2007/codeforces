#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class segtree {
  public:
    vector<ll> segsums;
    vector<ll> lazy;
    vector<ll> leftpt;
    vector<ll> rightpt;
    int n;
    segtree (vector<ll>& start) {
      n = start.size();
      segsums.resize(4*n, 0);
      lazy.resize(4*n, 0);
      leftpt.resize(4*n);
      rightpt.resize(4*n);
      init(start, 0, 0, n-1);
    }
    void push(int v) {
      lazy[2*v+1] += lazy[v];
      lazy[2*v+2] += lazy[v];
      lazy[v] = 0;
    }

    void add (int v, int tl, int tr, int l, int r, ll x) {
      if (l > r) return;
      if (l == tl && r == tr) {
        lazy[v] += x;
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        add(2*v+1, tl, tm, l, min(r, tm), x);
        add(2*v+2, tm+1, tr, max(l, tm+1), r, x);
        combine(v, tl, tr);
      }
    }
    void add (int l, int r, ll x) {
      add(0, 0, n-1, l, r, x);
    }

    ll realsum (int v, int tl, int tr) {
      return segsums[v] + (tr-tl+1)*lazy[v];
    }
    ll realrightpt (int v) {
      return rightpt[v] + lazy[v];
    }
    ll realleftpt (int v) {
      return leftpt[v] + lazy[v];
    }

    pair<int, ll> query(int v, int tl, int tr, ll x) {
      if (realleftpt(v) > x) return {0, 0};
      if (realrightpt(v) <= x) return {tr-tl+1, realsum(v, tl, tr)};
      else {
        assert(tl != tr);
        push(v);
        int tm = (tl+tr)/2;
        pair<int, ll> leftans = query(2*v+1, tl, tm, x);
        pair<int, ll> rightans = query(2*v+2, tm+1, tr, x);
        combine(v, tl, tr);
        return {leftans.first+rightans.first, leftans.second+rightans.second};
      }
    }
    pair<int, ll> query(ll x) {
      // first: how many elements are <= x
      // second: the sum of all those elements
      return query(0, 0, n-1, x);
    }

    void init(vector<ll>& start, int v, int tl, int tr) {
      if (tl == tr) {
        segsums[v] = start[tl];
        leftpt[v] = start[tl];
        rightpt[v] = start[tl];
        return;
      }
      int tm = (tl+tr)/2;
      init(start, 2*v+1, tl, tm);
      init(start, 2*v+2, tm+1, tr);
      combine(v, tl, tr);
    }

    void combine(int v, int tl, int tr) {
      int tm = (tl+tr)/2;
      segsums[v] = realsum(2*v+1, tl, tm) + realsum(2*v+2, tm+1, tr);
      leftpt[v] = realleftpt(2*v+1);
      rightpt[v] = realrightpt(2*v+2);
    }

    void debug (int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << lazy[v] << " " << segsums[v] << endl;
      if (tl != tr) {
        int tm = (tl+tr)/2;
        debug(2*v+1, tl, tm);
        debug(2*v+2, tm+1, tr);
      }
    }
    void debug () {
      debug(0, 0, n-1);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;

  vector<ll> a(n);
  vector<ll> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  vector<ll> ad(n-1);
  vector<ll> bd(m-1);
  for (int i = 0; i < n-1; i++) {
    ad[i] = a[i+1]-a[i];
  }
  for (int i = 0; i < m-1; i++) {
    bd[i] = b[i+1]-b[i];
  }

  segtree bs(bd);
  ll base = (n+m-1)*(a[0] + b[0]);
  for (int i = 0; i < m-1; i++) {
    base += (m-1-i)*bd[i];
  }

  while (q--) {
    int type, d;
    ll k;
    cin >> type >> k >> d;
    if (type == 1) {
      if (k == n) {
        base += (n+m-1)*d;
        k--;
      }
      for (int i = 0; i < k; i++) {
        ad[n-2-i] += d;
      }
    }
    else {
      if (k == m) {
        base += (n+m-1)*d;
        k--;
      }
      bs.add(m-k-1, m-2, d);
      base += (k*(k+1))/2*d;
    }

    ll ans = base;
    for (int i = 0; i < n-1; i++) {
      ll e = ad[n-2-i];
      pair<int, ll> query_ans = bs.query(e);
      ans += (i+m-query_ans.first)*e;
      ans += query_ans.second;
    }
    cout << ans << '\n';
  }
}