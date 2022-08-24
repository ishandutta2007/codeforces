#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;
const ll inf = 1e18;

ll add[4 * N];
ll t[4 * N];

void zpd(int v, ll x) {
  t[v] += x;
  add[v] += x;
}

void push(ll v) {
  if (add[v]) {
    zpd(v * 2 + 1, add[v]);
    zpd(v * 2 + 2, add[v]);
    add[v] = 0;
  }
}

void upd(int v, int l, int r, int tl, int tr, ll x) {
  if (tl >= r || tr <= l) {
    return;
  }
  if (tl >= l && tr <= r) {
    zpd(v, x);
  } else {
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, l, r, tl, tm, x);
    upd(v * 2 + 2, l, r, tm, tr, x);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int main() {
#ifdef iq
	freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector <int> a(n), ca(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> ca[i];
  }
  vector <int> b(m), cb(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i] >> cb[i];
  }
  vector <pair <int, pair <int, int> > > f;
  for (int i = 0; i < p; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    f.push_back({x, {y, z}});
  }
  vector <int> ord;
  for (int i = 0; i < m; i++) {
    ord.push_back(i);
  }
  sort(ord.begin(), ord.end(), [&] (int x, int y) {
    return b[x] < b[y];
  });
  for (int i = 0; i < m; i++) {
    upd(0, i, i + 1, 0, m, -cb[ord[i]]);
  }
  vector <int> mda;
  for (int i = 0; i < n; i++) {
    mda.push_back(i);
  }
  sort(mda.begin(), mda.end(), [&] (int x, int y) {
     return a[x] < a[y];
   });
  sort(f.begin(), f.end());
  int ptr = -1;
  ll ans = -inf;
  for (int i : mda) {
    while (ptr + 1 < (int) f.size() && f[ptr + 1].first < a[i]) {
      ptr++;
      int ty = f[ptr].second.first;
      int cost = f[ptr].second.second;
      int l = -1, r = (int) ord.size();
      while (l < r - 1) {
        int m = (l + r) / 2;
        if (b[ord[m]] <= ty) {
          l = m;
        } else {
          r = m;
        }
      }
      upd(0, l + 1, m, 0, m, cost);
    }
    ans = max(ans, t[0] - ca[i]);
  }
  cout << ans << endl;
}