// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
ll read() {
  ll x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;

ll a[N], b[N], da[N], db[N];
ll preans;
int n, m, q;

struct Fen {
  ll c[N];
  void add(int x, ll dlt) {
    while (x <= m) {
      c[x] += dlt;
      x += x & -x;
    }
  }  
  ll query(int x) {
    ll ret = 0;
    while (x) {
      ret += c[x];
      x ^= x & -x; 
    }
    return ret;
  }
  pair<int, ll> ask(ll x) {
    int cur = 0;
    ll sum = 0;
    for (int i = 16; i >= 0; i--) {
      if ((cur | 1 << i) <= m && (sum + c[cur | 1 << i] <= x)) {
        sum += c[cur |= 1 << i];
      }
    }
    return {cur, sum};
  }
} c1, c2;

int main() {
  n = read(), m = read(), q = read();
  for (int i = 0; i < n; i++) a[i] = read();
  for (int i = 0; i < m; i++) b[i] = read();
  preans += (a[0] + b[0]) * (n + m - 1);
  n--, m--;
  for (int i = 0; i <= m; i++) preans += b[i] - b[0];
  for (int i = 1; i <= n; i++) da[i] = a[i] - a[i - 1];
  for (int i = 1; i <= m; i++) {
    db[i] = b[i] - b[i - 1];
    c1.add(i, db[i] - db[i - 1]);
    c2.add(i, (db[i] - db[i - 1]) * i);
  }
  while (q--) {
    int type = read(), k = read();
    ll d = read();
    if (type == 1) {
      if (k == n + 1) k--, preans += d * (n + m + 1);
      rep(i, n - k + 1, n) da[i] += d;
    } else {
      if (k == m + 1) k--, preans += d * (n + m + 1);
      preans += 1ll * k * (k + 1) / 2 * d;
      c1.add(m - k + 1, d);
      c2.add(m - k + 1, d * (m - k + 1));
    }
    ll ans = preans;
    rep(i, 1, n) {
      pair<int, ll> cur = c1.ask(da[i]);
//      printf("i = %d, (%d, %lld)\n", i, cur.first, cur.second);
      ans += 1ll * (cur.fir + 1) * cur.sec - c2.query(cur.fir);
      ans += (m - cur.fir + n - i + 1) * da[i];  
    }
    print(ans, '\n');
  }
  return 0;
}