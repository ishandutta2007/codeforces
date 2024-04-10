#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int maxn = 1e6;
const pii minp = {0, -1};

class segtree {
  public:
    vector<pii> vals;
    vector<pii> lazy;
    int n;
    segtree (int n): n(n) {
      vals.resize(4*n, minp);
      lazy.resize(4*n, minp);
    }

    void push(int v) {
      if (lazy[v] == minp) return;
      vals[2*v+1] = lazy[v];
      lazy[2*v+1] = lazy[v];
      vals[2*v+2] = lazy[v];
      lazy[2*v+2] = lazy[v];
      lazy[v] = minp;
    }

    void set (int v, int tl, int tr, int l, int r, pii x) {
      if (l > r) return;
      if (l == tl && r == tr) {
        lazy[v] = x;
        vals[v] = x;
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        set(2*v+1, tl, tm, l, min(r, tm), x);
        set(2*v+2, tm+1, tr, max(l, tm+1), r, x);
        vals[v] = max(vals[2*v+1], vals[2*v+2]);
      }
    }

    void set (int l, int r, pii x) {
      set(0, 0, n-1, l, r, x);
    }

    pii getmax (int v, int tl, int tr, int l, int r) {
      if (l > r) return minp;
      if (l == tl && r == tr) {
        return vals[v];
      }
      else {
        push(v);
        int tm = (tl+tr)/2;
        return max(getmax(2*v+1, tl, tm, l, min(r, tm)),
            getmax(2*v+2, tm+1, tr, max(l, tm+1), r));
      }
    }

    pii getmax(int l, int r) {
      return getmax(0, 0, n-1, l, r);
    }

    void debug () {
      debug(0, 0, n-1);
    }

    void debug(int v, int tl, int tr) {
      cout << v << " " << tl << " " << tr << " " << vals[v].first << " " <<
        vals[v].second << endl;
      if (tl != tr) {
        int tm = (tl+tr)/2;
        debug(2*v+1, tl, tm);
        debug(2*v+2, tm+1, tr);
      }
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pii>> segments(n);
  set<int> coordinates;
  while (m--) {
    int i, l, r;
    cin >> i >> l >> r;
    segments[i-1].push_back({l, r});
    coordinates.insert(l);
    coordinates.insert(r);
  }
  unordered_map<int, int> cc;
  int index = 1;
  for (int i: coordinates) {
    cc[i] = index;
    index++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < segments[i].size(); j++) {
      segments[i][j].first = cc[segments[i][j].first];
      segments[i][j].second = cc[segments[i][j].second];
    }
  }

  pii best = minp;
  segtree s(maxn);
  vector<int> prev(n);
  for (int i = 0; i < n; i++) {
    pii ans = minp;
    for (pii p: segments[i]) {
      ans = max(ans, s.getmax(p.first, p.second));
    }
    pii newval = {ans.first+1, i};
    for (pii p: segments[i]) {
      s.set(p.first, p.second, newval);
    }
    prev[i] = ans.second;
    best = max(best, newval);
  }

  vector<bool> used(n, 0);
  int free = n;
  int i = best.second;
  while (i != -1) {
    used[i] = 1;
    free--;
    i = prev[i];
  }
  cout << free << endl;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}