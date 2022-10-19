#include <bits/stdc++.h>
using namespace std;

class segtree {
  public:
    vector<int> leftrun;
    vector<int> rightrun;
    vector<long long> incsub;
    vector<bool> inc;
    vector<int> a;
    int n;
    segtree (vector<int>& _a): a(_a) {
      n = a.size();
      leftrun.resize(4*n, 0);
      rightrun.resize(4*n, 0);
      incsub.resize(4*n, 0);
      inc.resize(4*n, 0);
      init(0, 0, n-1);
    }

    void init(int v, int tl, int tr) {
      if (tl == tr) {
        leftrun[v] = 1;
        rightrun[v] = 1;
        incsub[v] = 1;
        inc[v] = 1;
        return;
      }

      int tm = (tl+tr)/2;
      init(2*v+1, tl, tm);
      init(2*v+2, tm+1, tr);
      combine(v, tl, tr);
    }

    void set(int x, int y) {
      a[x] = y;
      upd(0, 0, n-1, x);
    }

    void upd(int v, int tl, int tr, int x) {
      if (tl == tr) return;
      int tm = (tl+tr)/2;
      if (tm >= x) upd(2*v+1, tl, tm, x);
      else upd(2*v+2, tm+1, tr, x);
      combine(v, tl, tr);
    }

    long long query(int l, int r) {
      return query(0, 0, n-1, l, r);
    }

    long long query(int v, int tl, int tr, int l, int r) {
      if (r < tl || l > tr) return 0;
      if (l <= tl && tr <= r) return incsub[v];
      int tm = (tl+tr)/2;
      long long ans = query(2*v+1, tl, tm, l, r) +
        query(2*v+2, tm+1, tr, l, r);

      if (a[tm] <= a[tm+1]) {
        ans += 1LL*min(leftrun[2*v+2], max(0, r-tm))*min(rightrun[2*v+1], max(tm-l+1, 0));
      }
      return ans;
    }

    void combine(int v, int tl, int tr) {
      int tm = (tl+tr)/2;
      bool b = (a[tm] <= a[tm+1]);

      rightrun[v] = rightrun[2*v+2] +
        (inc[2*v+2] && b ? rightrun[2*v+1] : 0);
      leftrun[v] = leftrun[2*v+1] +
        (inc[2*v+1] && b ? leftrun[2*v+2] : 0);
      inc[v] = inc[2*v+1] && inc[2*v+2] && b;
      incsub[v] = incsub[2*v+1] + incsub[2*v+2] + (b ? 1LL*leftrun[2*v+2]*rightrun[2*v+1] : 0);
    }

    void debug(int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << inc[v] << " " << leftrun[v] << " " << rightrun[v] << " " << incsub[v] << '\n';
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
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  
  segtree s(a);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      s.set(x-1, y);
    }
    else {
      cout << s.query(x-1, y-1) << '\n';
    }
  }
}