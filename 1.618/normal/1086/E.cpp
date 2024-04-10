#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <bitset>

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

#define maxn 2005
#define mod 998244353

ll modpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}

struct Bitset {
  //  0-base 
  #define SIZ 32
  ull a[35];
  Bitset() {
    memset(a, 0, sizeof(a));
  }
  void reset() {
    memset(a, 0, sizeof(a));
  }
  void reset(int x) {
    a[x >> 6] &= ~(1ull << (x & 63));
  }
  void set() {
    memset(a, 0xff, sizeof(a));
  }
  void flip(int x) {
    a[x >> 6] ^= 1ull << (x & 63);
  }
  int at(int x) {
		return (a[x >> 6] >> (x & 63)) & 1;
	}
  int count() {
    int res = 0;
    for (int i = 0; i < SIZ; i++) res += __builtin_popcountll(a[i]);
    return res;
  }
  void setPrefix(int x) { // set [0, x]
    for (int i = 0; i < (x >> 6); i++) a[i] = 0xffffffffffffffff;
    if ((x & 63) == 63) a[x >> 6] = 0xffffffffffffffff;
    else a[x >> 6] |= (1ull << ((x & 63) + 1)) - 1;
  }
  Bitset operator & (const Bitset &b) const {
    Bitset res;
    for (int i = 0; i < SIZ; i++) res.a[i] = a[i] & b.a[i];
    return res;
  }
  Bitset operator ~ () const {
    Bitset res;
    for (int i = 0; i < SIZ; i++) res.a[i] = ~a[i];
    return res;
  }
  #undef SIZ
};

int n, m[maxn][maxn];
ll d[maxn][maxn], cnt[maxn];
Bitset pre, cur;

int main() {
  n = getint();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      m[i][j] = getint();
      m[i][j]--;
    }
  }
  d[0][0] = 1;
  for (int i = 1; i <= n; i++) d[i][0] = d[i - 1][0] * i % mod;
  for (int i = 1; i <= n; i++) {
    d[i][1] = (i - 1) * d[i - 1][0] % mod;
    for (int j = 2; j <= i; j++) {
      d[i][j] = ((j - 1) * d[i - 1][j - 2] + (i - j) * d[i - 1][j - 1]) % mod;
    }
  }
  cur.reset();
  for (int j = 1; j < n; j++) {
    Bitset cho;
    if (m[1][j]) cho.setPrefix(m[1][j] - 1);
    cho = cho & ~cur;
    (cnt[1] += d[n - j][0] * cho.count()) %= mod;
    cur.flip(m[1][j]);
  }
  for (int i = 2; i <= n; i++) {
    pre.setPrefix(n - 1);
    cur.reset();
    for (int j = 1; j < n; j++) {
      pre.flip(m[i - 1][j]);
      int free = (pre & cur).count();
      Bitset cho;
      if (m[i][j]) cho.setPrefix(m[i][j] - 1);
      cho = cho & ~cur;
      cho.reset(m[i - 1][j]);
      ll oneMore = (cho & pre).count(), noMore = cho.count() - oneMore;
      (cnt[i] += d[n - j][n - j - free] * noMore) %= mod;
      if (oneMore)
        (cnt[i] += d[n - j][n - j - free - 1] * oneMore) %= mod;
      cur.flip(m[i][j]);
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    (ans += cnt[i] * modpow(d[n][n], n - i)) %= mod;
  }
  putll((ans + mod) % mod, '\n');
  bufo.flush();
  return 0;
}