/*
result of thinking: Lost.

x02^k-12^iflip2^{k-i}flip(x2^i)
2^i
trie2^{k-i}
: xtrie!

start coding: 23:30
AC: 11:00 nxtd
*/
#include <bits/stdc++.h>
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

#define maxn 524295
// root: 1
struct Node {
  int mini, maxi, ans, chi[2];
} dat[maxn * 19];
int V = 1, k, n, a[maxn], ans[maxn];

void up(int u, int w) {
  int lc = dat[u].chi[0], rc = dat[u].chi[1];
  if (!lc) {
    dat[u].mini = dat[rc].mini + (1 << w);
    dat[u].maxi = dat[rc].maxi + (1 << w);
    dat[u].ans = dat[rc].ans;
  } else if (!rc) {
    dat[u].mini = dat[lc].mini;
    dat[u].maxi = dat[lc].maxi;
    dat[u].ans = dat[lc].ans;
  } else {
    dat[u].mini = dat[lc].mini;
    dat[u].maxi = dat[rc].maxi + (1 << w);
    dat[u].ans = min(dat[lc].ans, dat[rc].ans);
    chmin(dat[u].ans, dat[rc].mini + (1 << w) - dat[lc].maxi);
  }
}

void ins(int x) {
  int u = 1;
  vector<int> foo(k);
  for (int i = k - 1; i >= 0; i--) {
    int d = x >> i & 1;
    if (!dat[u].chi[d])
      dat[u].chi[d] = ++V;
    foo[i] = u;
    u = dat[u].chi[d];
  }
  dat[u].ans = inf;
  for (int i = 0; i < k; i++)
    up(foo[i], i);
}

// flip x2^t
void flip(int u, int d, int t) {
  if (d == t) {
    swap(dat[u].chi[0], dat[u].chi[1]);
  } else {
    if (dat[u].chi[0])
      flip(dat[u].chi[0], d - 1, t);
    if (dat[u].chi[1])
      flip(dat[u].chi[1], d - 1, t);
  }
  up(u, d);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ins(a[i]);
  }
  for (int i = 0; i < (1 << k); i++) {
    if (i) {
      for (int j = 0; j <= __builtin_ctz(i); j++) {
        flip(1, k - 1, k - 1 - j);
      }
    }
    int x = 0;
    for (int j = 0; j < k; j++) {
      if (i >> j & 1)
        x |= 1 << (k - 1 - j);
    }
    ans[x] = dat[1].ans;
  }
  for (int i = 0; i < (1 << k); i++)
    printf("%d ", ans[i]);
  return 0;
}