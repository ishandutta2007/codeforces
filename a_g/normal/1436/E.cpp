#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class segtree {
  public:
    vector<int> lazy;
    vector<int> maxval;
    vector<int> minval;
    int n;
    segtree (int n): n(n) {
      lazy.resize(4*n, 0);
      maxval.resize(4*n, 0);
      minval.resize(4*n, 0);
      init(0, 0, n-1);
    }
    void push(int v) {
      if (!lazy[v]) return;
      lazy[2*v+1] = lazy[v];
      lazy[2*v+2] = lazy[v];
      lazy[v] = 0;
    }

    int realmaxval(int v) {
      if (lazy[v]) return lazy[v];
      return maxval[v];
    }
    int realminval(int v) {
      if (lazy[v]) return lazy[v];
      return minval[v];
    }

    void apply_min (int v, int tl, int tr, int l, int r, int x) {
      if (l > r) return;
      if (l == tl && r == tr) {
        if (realmaxval(v) <= x) return;
        if (realminval(v) >= x) {
          lazy[v] = x;
          return;
        }
      }
      push(v);
      int tm = (tl+tr)/2;
      apply_min(2*v+1, tl, tm, l, min(r, tm), x);
      apply_min(2*v+2, tm+1, tr, max(l, tm+1), r, x);
      combine(v);
    }
    void apply_min (int l, int r, int x) {
      apply_min(0, 0, n-1, l, r, x);
    }

    int query(int v, int tl, int tr, int i) {
      if (tl == tr) return lazy[v];
      if (lazy[v]) return lazy[v];
      push(v);
      int tm = (tl+tr)/2;
      int ans;
      if (tm >= i) ans = query(2*v+1, tl, tm, i);
      else ans = query(2*v+2, tm+1, tr, i);
      combine(v);
      return ans;
    }
    int query(int i) {
      return query(0, 0, n-1, i);
    }

    void init(int v, int tl, int tr) {
      if (tl == tr) {
        lazy[v] = tl;
        return;
      }
      int tm = (tl+tr)/2;
      init(2*v+1, tl, tm);
      init(2*v+2, tm+1, tr);
      combine(v);
    }

    void combine(int v) {
      maxval[v] = max(realmaxval(2*v+1), realmaxval(2*v+2));
      minval[v] = min(realminval(2*v+1), realminval(2*v+2));
    }

    void debug (int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << lazy[v] << " " << minval[v] << " " << maxval[v] << endl;
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
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> indices(n+2, vector<int>(1, 0));
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    indices[a].push_back(i);
  }
  for (int i = 1; i <= n+1; i++) {
    indices[i].push_back(n+1);
  }

  segtree st(n+1);

  int ans = 1;
  while (ans <= n+1) {
    int s = indices[ans].size();
    bool good = 0;
    for (int j = 0; j < s-1; j++) {
      int u = indices[ans][j];
      int v = indices[ans][j+1];
      if (v-u > 1) {
        if (st.query(v-1) >= u+1) good = 1;
      }
    }
    for (int j = 0; j < s-1; j++) {
      int u = indices[ans][j];
      int v = indices[ans][j+1];
      st.apply_min(u, v-1, (u ? u : -INF));
    }
    if (!good) break;
    ans++;
  }
  cout << ans << endl;
}