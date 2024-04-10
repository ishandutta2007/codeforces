#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class segtree {
  public:
    vector<int> lazy;
    int n;
    segtree (int m) {
      n = m;
      lazy.resize(4*n, 0);
    }
    void push(int v) {
      lazy[2*v+1] += lazy[v];
      lazy[2*v+2] += lazy[v];
      lazy[v] = 0;
    }
    void add (int v, int tl, int tr, int l, int r, ll x) {
      //cout << v << " " << tl << " " << tr << " " << l << " " << r << " " << x << endl;
      if (l > r) return;
      if (l == tl && r == tr) {
        lazy[v] += x;
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        add(2*v+1, tl, tm, l, min(r, tm), x);
        add(2*v+2, tm+1, tr, max(l, tm+1), r, x);
      }
    }
    void add (int l, int r, ll x) {
      add(0, 0, n-1, l, r, x);
    }
    int query(int v, int tl, int tr, int i) {
      //cout << "   " << v << " " << tl << " " << tr << " " << i << endl;
      if (tl == tr) return lazy[v];
      int tm = (tl+tr)/2;
      push(v);
      if (tm >= i) {
        return query(2*v+1, tl, tm, i);
      }
      else {
        return query(2*v+2, tm+1, tr, i);
      }
    }
    int query (int i) {
      return query(0, 0, n-1, i);
    }
    void debug (int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << lazy[v] << endl;
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
  cout << fixed << setprecision(10);

  segtree st(2e5+7);
  ll sum = 0;
  int len = 1;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, x;
      cin >> a >> x;
      st.add(0, a-1, x);
      sum += a*x;
    }
    else if (t == 2) {
      int k;
      cin >> k;
      st.add(len, len, k);
      sum += k;
      len++;
    }
    else {
      int val = st.query(len-1);
      st.add(len-1, len-1, -val);
      sum -= val;
      len--;
    }
    //cout << len << " " << sum << endl;
    //st.debug();
    cout << (double)sum/len << '\n';
  }
}