#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ldb long double

#define endl '\n'

const int MAXN = 502;

struct DSU {
  int p[MAXN];
  int rk[MAXN];

  void init() {
    for (int i = 0; i < MAXN; i++) {
      p[i] = i;
      rk[i] = 0;
    }
  }

  DSU() {
    init();
  }

  int get(int v) {
    if (p[v] == v)
      return v;
    return p[v] = get(p[v]);
  }

  void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
      return;
    if (rk[b] > rk[a]) {
      swap(a, b);
    }
    p[b] = a;
    if (rk[a] == rk[b]) {
      rk[a]++;
    }
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<DSU> pref(1), suf(1);;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].first >> edges[i].second;
    edges[i].first--;
    edges[i].second--;
  }
  for (int i = 0; i < m; i++) {
    pref.push_back(pref.back());
    pref.back().merge(edges[i].first, edges[i].second);
  }
  for (int i = m - 1; i >= 0; i--) {
    suf.push_back(suf.back());
    suf.back().merge(edges[i].first, edges[i].second);
  }
  int q;
  cin >> q;
  DSU d;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r = m - r;
    d.init();
    for (int i = 0; i < n; i++) {
      d.merge(pref[l].get(i), i);
      d.merge(suf[r].get(i), i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (d.get(i) == i) {
        ans++;
      }
    }
    cout << ans << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}