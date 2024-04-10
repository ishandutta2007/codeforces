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
template<class T> bool chmin(T &x, T y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, T y) {
  return x < y ? (x = y, true) : false;
}

#define maxk 5005
const int mod = 1e9 + 7;
int n, k, s2[maxk], fct[maxk], C_n[maxk];

int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}
int inv(int x) {
  return modpow(x, mod - 2);
}

int main() {
  n = getint(), k = getint();
  s2[0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j >= 1; j--) {
      s2[j] = (s2[j - 1] + (ll)s2[j] * j) % mod;
    }
    s2[0] = 0;
  }
  fct[0] = 1;
  for (int i = 1; i <= k; i++) fct[i] = (ll)fct[i - 1] * i % mod;
  C_n[0] = 1;
  for (int i = 1; i <= k; i++) {
    C_n[i] = (ll)C_n[i - 1] * inv(i) % mod * (n - i + 1) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= min(n, k); i++) {
    ans = 
      (ans + (ll)s2[i] * fct[i] % mod * modpow(2, n - i) % mod * C_n[i]) % mod;
  }
  putint(ans, '\n');
  bufo.flush();
  return 0;
}