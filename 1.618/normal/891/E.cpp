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
    it = 0;
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 5005
const int mod = 1000000007;

int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

int n, k, a[maxn], depowk[maxn];

vector<int> prod(int l, int r) {
  if (l == r) {
    return (vector<int>){a[l], -1};
  }
  int mid = (l + r) >> 1;
  vector<int> f = prod(l, mid), g = prod(mid + 1, r), res;
  res.resize(r - l + 2);
  for (int i = 0; i <= mid - l + 1; i++) {
    for (int j = 0; j <= r - mid; j++) {
      res[i + j] = (res[i + j] + (ll)f[i] * g[j]) % mod;
    }
  }
  return res;
}

int main() {
  n = getint(), k = getint();
  depowk[0] = 1;
  for (int i = 1; i <= n; i++)
    depowk[i] = (ll)depowk[i - 1] * (k - i + 1) % mod;
  int ans = 1;
  for (int i = 1; i <= n; i++) ans = (ll)ans * (a[i] = getint()) % mod;
  vector<int> c = prod(1, n);
  int dec = 0;
  for (int i = 0; i <= min(n, k); i++) {
    dec = (dec + (ll)modpow(n, k - i) * depowk[i] % mod * c[i]) % mod;
  }
  ans = (ans - (ll)dec * modpow(n, mod - 1 - k)) % mod;
  putint((ans + mod) % mod, '\n');
  bufo.flush();
  return 0;
}