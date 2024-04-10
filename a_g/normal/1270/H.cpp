#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class segtree {
  public:
    vector<int> lazy;
    vector<int> valids; // number of actives with value equal to min on segment
    vector<int> mins;
    int n;
    segtree (int n): n(n) {
      lazy.resize(4*n, 0);
      valids.resize(4*n, 0);
      mins.resize(4*n, 0);
    }

    void push(int v) {
      lazy[2*v+1] += lazy[v];
      lazy[2*v+2] += lazy[v];
      mins[2*v+1] += lazy[v];
      mins[2*v+2] += lazy[v];
      lazy[v] = 0;
    }

    void add (int v, int tl, int tr, int l, int r, int x) {
      r = min(r, n-1);
      if (l > r) return;
      if (l == tl && r == tr) {
        lazy[v] += x;
        mins[v] += x;
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        add(2*v+1, tl, tm, l, min(r, tm), x);
        add(2*v+2, tm+1, tr, max(l, tm+1), r, x);
        mins[v] = min(mins[2*v+1], mins[2*v+2]);
        valids[v] = 0;
        for (int j = 1; j <= 2; j++) {
          if (mins[2*v+j] == mins[v]) {
            valids[v] += valids[2*v+j];
          }
        }
      }
    }

    void add_special(int l, int r, int x) {
      if (l > r) swap(l, r);
      add(0, 0, n-1, l, r-1, x);
    }

    void activate(int v, int l, int r, int i, int w) {
      if (l == r) {
        valids[v] = w;
        return;
      }
      push(v);
      int m = (l+r)/2;
      if (i <= m) {
        activate(2*v+1, l, m, i, w);
      }
      else {
        activate(2*v+2, m+1, r, i, w);
      }
      mins[v] = min(mins[2*v+1], mins[2*v+2]);
      valids[v] = 0;
      for (int j = 1; j <= 2; j++) {
        if (mins[2*v+j] == mins[v]) {
          valids[v] += valids[2*v+j];
        }
      }
    }

    void activate(int i, int w) {
      activate(0, 0, n-1, i, w);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n+2);
  a[0] = INF;
  segtree b(1e6+2);
  for (int i = 0; i < n; i++) {
    cin >> a[i+1];
  }
  for (int i = 0; i <= n; i++) {
    b.add_special(a[i], a[i+1], 1);
  }
  for (int i = 1; i <= n; i++) {
    b.activate(a[i], 1);
  }
  while (q--) {
    int x, val;
    cin >> x >> val;
    b.activate(a[x], 0);
    int m = min(a[x-1], a[x+1]);
    int M = max(a[x-1], a[x+1]);
    if (a[x] > M) {
      b.add_special(M, a[x], -2);
    }
    if (a[x] < m) {
      b.add_special(a[x], m, -2);
    }
    a[x] = val;
    if (a[x] > M) {
      b.add_special(M, a[x], 2);
    }
    if (a[x] < m) {
      b.add_special(m, a[x], 2);
    }
    b.activate(a[x], 1);
    cout << b.valids[0] << '\n';
  }
}