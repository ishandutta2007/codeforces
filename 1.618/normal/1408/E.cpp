#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
const int LEN = 100000;

struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if (it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n' || c == '\r'; c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if (it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll() {
  char c; ll res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x, char suf) {
  if (!x) bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get());
  return c;
}

#define maxV 200005
#define maxn 100005
int V, par[maxV], hei[maxV];

void ini() {
  for (int i = 1; i <= V; i++) {
    par[i] = i;
  }
}
int fin(int u) {
  if (par[u] == u) return u;
  return par[u] = fin(par[u]);
}
void uni(int u, int v) {
  u = fin(u), v = fin(v);
  if (u == v) return;
  if (hei[u] < hei[v]) {
    par[u] = v;
  } else {
    par[v] = u;
    if (hei[u] == hei[v]) hei[u]++;
  }
}
bool same(int u, int v) {
  return fin(u) == fin(v);
}

struct Edge {
  int u, v, w;
  bool operator < (const Edge &e) const {
    return w > e.w;
  }
};
vector<Edge> E;

ll kruskal() {
  ini();
  sort(E.begin(), E.end());
  ll ans = 0;
  for (auto e : E) {
    if (same(e.u, e.v)) continue;
    ans += e.w;
    uni(e.u, e.v);
  }
  return ans;
}

int m, n, a[maxn], b[maxn];

int main() {
  m = getint(), n = getint();
  V = m + n;
  for (int i = 1; i <= m; i++) a[i] = getint();
  for (int i = 1; i <= n; i++) b[i] = getint();
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    int s = getint();
    for (int j = 1; j <= s; j++) {
      int v = getint();
      E.push_back((Edge){i, m + v, a[i] + b[v]});
      ans += a[i] + b[v];
    }
  }
  printf("%lld\n", ans - kruskal()); 
  return 0;
}