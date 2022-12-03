/*
f[i][j]  ja_ihappy 
f[i][j]  ja_ihappy 

.
*/ 
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 5005
const int mod = 998244353;
int n, a[maxn], cntLess[maxn], f[maxn][maxn], sum[maxn][maxn];

int main() {
  n = getint();
  for (int i = 1; i <= n; i++) a[i] = getint();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    cntLess[i] = upper_bound(a + 1, a + n + 1, a[i] / 2) - a - 1;
  }
  for (int i = 1; i <= n; i++) {
    f[i][1] = 1;
    for (int j = 2; j <= i; j++) {
      f[i][j] = ((ll)f[i][j - 1] * (cntLess[i] - j + 2) 
                 + sum[cntLess[i]][j - 1]) % mod;
    }
    for (int j = 1; j <= i; j++)
      sum[i][j] = (sum[i - 1][j] + f[i][j]) % mod;
  }
  printf("%d\n", f[n][n]);
  return 0;
}