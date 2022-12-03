/*
result of thinking: Lost.

.
f(i): =i, (1, i), . (0-base)
a, b, q, 
  max_{l<=i<=j<=r} (a[i] + b[j]), dp.
:  maxa, maxb, ans.

: .

start coding: 10:00
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 500005
#define maxV 1048585
int n, q;
ll s[3][maxn], f[maxn];
vector<P> el[maxn];

namespace SgtMax {
  ll maxi[maxV];
  
  void ini() {
    memset(maxi, 0xc0, sizeof(maxi));
  }
  
  void up(int u) { maxi[u] = max(maxi[u << 1], maxi[u << 1 | 1]); }

  void update(int u, int l, int r, int pos, ll x) {

    // if (u == 1) {
    //   cout << pos << " " << x << endl;
    //   system("pause");
    // }

    if (l == r)
      maxi[u] = x;
    else {
      int mid = (l + r) >> 1;
      if (pos <= mid)
        update(u << 1, l, mid, pos, x);
      else
        update(u << 1 | 1, mid + 1, r, pos, x);
      up(u);
    }
  }
  
  ll qmax(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return maxi[u];
    ll res = 0xc0c0c0c0c0c0c0c0;
    int mid = (l + r) >> 1;
    if (ql <= mid)
      chmax(res, qmax(u << 1, l, mid, ql, qr));
    if (mid < qr)
      chmax(res, qmax(u << 1 | 1, mid + 1, r, ql, qr));
    return res;
  }
}

namespace SgtAns {
  ll maxa[maxV], maxb[maxV], res[maxV];

  void ini() {
    memset(maxa, 0xc0, sizeof(maxa));
    memset(maxb, 0xc0, sizeof(maxb));
    memset(res, 0xc0, sizeof(res));
  }

  void up(int u) {
    maxa[u] = max(maxa[u << 1], maxa[u << 1 | 1]);
    maxb[u] = max(maxb[u << 1], maxb[u << 1 | 1]);
    res[u] = max({res[u << 1], res[u << 1 | 1], maxa[u << 1] + maxb[u << 1 | 1]});
  }

  void update(int u, int l, int r, int pos, ll a, ll b) {
    if (l == r) {
      maxa[u] = a;
      maxb[u] = b;
      res[u] = a + b;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      update(u << 1, l, mid, pos, a, b);
    else
      update(u << 1 | 1, mid + 1, r, pos, a, b);
    up(u);
  }

  // maxa, maxb, res
  tuple<ll, ll, ll> query(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return make_tuple(maxa[u], maxb[u], res[u]);
    int mid = (l + r) >> 1;
    if (qr <= mid)
      return query(u << 1, l, mid, ql, qr);
    if (mid < ql)
      return query(u << 1 | 1, mid + 1, r, ql, qr);
    auto ls = query(u << 1, l, mid, ql, qr),
         rs = query(u << 1 | 1, mid + 1, r, ql, qr);
    return make_tuple(max(get<0>(ls), get<0>(rs)), max(get<1>(ls), get<1>(rs)), 
             max({get<2>(ls), get<2>(rs), get<0>(ls) + get<1>(rs)}));
  }
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &q);
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%lld", &s[i][j]);
      s[i][j] += s[i][j - 1];
    }
  }
  for (int i = 1; i <= q; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    el[r].push_back({l, k});
  }

  // for (int i = 0; i < 3; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << s[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // system("pause");

  memset(f, 0xc0, sizeof(f));
  SgtMax::ini();
  for (int i = 1; i <= n; i++) {
    SgtMax::update(1, 1, n, i, max(s[0][i], f[i - 1]) - s[1][i - 1]);
    for (auto e : el[i]) {

      // cout << e.first << " " << i << endl;
      // system("pause");

      chmax(f[i], SgtMax::qmax(1, 1, n, e.first, i) + s[1][i] - e.second);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << f[i] << " ";
  // }
  // cout << endl;
  // system("pause");

  SgtAns::ini();
  ll ans = 0xc0c0c0c0c0c0c0c0;
  for (int i = 1; i <= n; i++) {
    SgtAns::update(1, 1, n, i, max(s[0][i], f[i - 1]) - s[1][i - 1],
                    s[1][i] - s[2][i - 1]);
    for (auto e : el[i])
      chmax(ans, get<2>(SgtAns::query(1, 1, n, e.first, i)) - e.second + s[2][n]);
  }
  printf("%lld\n", ans);
  return 0;
}