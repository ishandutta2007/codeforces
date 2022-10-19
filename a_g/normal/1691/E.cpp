#include <bits/stdc++.h>
using namespace std;

struct seg {
  int c, l, r;
};

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<seg> segs(n);
    vector<int> coords;
    for (seg& s: segs) {
      cin >> s.c >> s.l >> s.r;
      coords.push_back(s.l);
      coords.push_back(s.r);
    }

    sort(coords.begin(), coords.end());
    coords.resize(unique(coords.begin(), coords.end())-coords.begin());
    auto compress = [&] (int x) {
      return lower_bound(coords.begin(), coords.end(), x)-coords.begin();
    };

    const int time = 2*n+5;
    vector<vector<pair<int, int>>> rseg(time);
    vector<vector<pair<int, int>>> bseg(time);
    for (int i = 0; i < n; i++) {
      seg s = segs[i];
      s.l = compress(s.l);
      s.r = compress(s.r);
      if (s.c == 1) {
        bseg[s.l].emplace_back(s.r, i);
      }
      else {
        rseg[s.l].emplace_back(s.r, i);
      }
    }

    dsu D(n);
    set<pair<int, int>> rs;
    set<pair<int, int>> bs;
    for (int t = 0; t < time; t++) {
      for (pair<int, int>& p: rseg[t]) rs.insert(p);
      for (pair<int, int>& p: bseg[t]) bs.insert(p);
      if (rs.size()) {
        while (bs.size() > 1) {
          D.join((*rs.begin()).second, (*bs.begin()).second);
          bs.erase(bs.begin());
        }
        if (bs.size()) {
          D.join((*rs.begin()).second, (*bs.begin()).second);
        }
      }

      if (bs.size()) {
        while (rs.size() > 1) {
          D.join((*rs.begin()).second, (*bs.begin()).second);
          rs.erase(rs.begin());
        }
        if (rs.size()) {
          D.join((*rs.begin()).second, (*bs.begin()).second);
        }
      }
      while (rs.size() && (*rs.begin()).first <= t) {
        rs.erase(rs.begin());
      }
      while (bs.size() && (*bs.begin()).first <= t) {
        bs.erase(bs.begin());
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (D.root(i) == i) ans++;
    }
    cout << ans << '\n';
  }
}