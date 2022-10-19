#include <bits/stdc++.h>
using namespace std;

class segtree {
  public:
    vector<int> vals;
    vector<int> lazy;
    int n;
    segtree (int n): n(n) {
      vals.resize(4*n, 0);
      lazy.resize(4*n, 0);
    }
    int get_min(int v, int tl, int tr) {
      return vals[0];
    }
    int get_min() {
      return vals[0];
    }
    void push(int v) {
      vals[2*v+1] += lazy[v];
      lazy[2*v+1] += lazy[v];
      vals[2*v+2] += lazy[v];
      lazy[2*v+2] += lazy[v];
      lazy[v] = 0;
    }
    void add (int v, int tl, int tr, int l, int r, int x) {
      if (l > r) return;
      if (l == tl && r == tr) {
        lazy[v] += x;
        vals[v] += x;
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        add(2*v+1, tl, tm, l, min(r, tm), x);
        add(2*v+2, tm+1, tr, max(l, tm+1), r, x);
        vals[v] = min(vals[2*v+1], vals[2*v+2]);
      }
    }
    void add (int l, int r, int x) {
      add(0, 0, n-1, l, r, x);
    }
};

int main () {
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> segments(n);
  for (int i = 0; i < n; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    segments[i] = {w, {l-1, r-2}};
  }
  sort(segments.begin(), segments.end());
  int ans = 1e9;
  int j = -1;
  segtree s(m-1);
  for (int i = 0; i < n; i++) {
    int l = segments[i].second.first;
    int r = segments[i].second.second;
    if (i > j) {
      s.add(l, r, 1);
      j = i;
    }
    while (s.get_min() == 0) {
      if (j == n-1) {
        cout << ans << endl;
        return 0;
      }
      j++;
      s.add(segments[j].second.first, segments[j].second.second, 1);
    }
    ans = min(ans, segments[j].first - segments[i].first);
    s.add(l, r, -1);
  }
  cout << ans << endl;
}