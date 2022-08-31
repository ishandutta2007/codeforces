#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 7;

int t[4 * N];

void build(int v, int l, int r, vector <int> &a) {
  if (r - l == 1) {
    t[v] = a[l];
  } else {
    int m = (l + r) /2 ;
    build(v * 2 + 1, l, m, a);
    build(v * 2 + 2, m, r, a);
    t[v] = min(t[v * 2 +1 ], t[v * 2 + 2]);
  }
}

int find_first(int v, int l, int r, int tl, int tr, int x) {
  if (tl >= r || tr <= l || t[v] >= x) {
    return -1;
  }
  if (tr - tl == 1) {
    return tl;
  } else {
    int tm = (tl +tr) / 2;
    int y = find_first(v *2  + 1, l, r, tl, tm, x);
    if (y == -1) {
      return find_first(v * 2 +2 , l, r, tm, tr, x);
    } else {
      return y;
    }
  }
}

const int inf = 1e9;

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector <int> b;
  for (int i = 0; i < n + n; i++) {
    b.push_back(a[i % n]);
  }
  build(0, 0, 2 * n, b);
  vector <int> st;
  vector <int> jmp(n);
  vector <int> fir(n);
  for (int i = (int) b.size() - 1; i >= 0; i--) {
    while (!st.empty() && b[st.back()] <= b[i]) {
      st.pop_back();
    }
    if (i < n) {
      jmp[i] = (st.empty() ? -1 : st.back() % n);
      fir[i] = find_first(0, i, 2 * n, 0, 2 * n, (b[i] + 1) / 2);
      if (fir[i] != -1) fir[i] %= n;
    }
    st.push_back(i);
  }
  auto dist = [&] (int a, int b) {
    if (b == -1) {
      return inf;
    }
    if (a <= b) {
      return b - a;
    }
    return n - (a - b);
  };
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
  }
  bool good = false;
  for (int i = 0; i < n; i++) {
    if (a[i] < (mx + 1) / 2) {
      good = true;
    }
  }
  if (!good) {
    for (int i = 0; i < n; i++) cout << -1 << ' ';
    cout << '\n';
    return 0;
  }
  vector <bool> vis(n);
  vector <ll> ret(n);
  function <ll(int)> ans = [&] (int i) {
    if (vis[i]) {
      return ret[i];
    }
    vis[i] = true;
    if (dist(i, fir[i]) < dist(i, jmp[i])) {
      return ret[i] = dist(i, fir[i]);
    } else {
      return ret[i] = dist(i, jmp[i]) + ans(jmp[i]);
    }
  };
  for (int i = 0; i < n; i++) {
    cout << ans(i) << ' ';
  }
  cout << '\n';
}