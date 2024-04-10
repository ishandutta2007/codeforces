#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
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

#define maxn 200005
const int inf = 0x3f3f3f3f;
int n, f[maxn][2][5], s[maxn], t[maxn];
const char d[] = {'L', 'R'};

void solve() {
  n = getint();
  for (int i = 1; i <= n; i++) s[i] = (get_char() == 'L' ? 0 : 1);
  int ans = inf;
  for (t[1] = 0; t[1] < 2; t[1]++) {
    for (t[2] = 0; t[2] < 2; t[2]++) {
      for (int i = 1; i <= n; i++) {
        f[i][0][1] = f[i][0][2] = f[i][1][1] = f[i][1][2] = inf;
      }
      f[2][t[2]][1 + (t[1] == t[2])] = (s[1] ^ t[1]) + (s[2] ^ t[2]);
      for (int i = 3; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
          f[i][j][1] = min(f[i - 1][!j][1], f[i - 1][!j][2]) + (s[i] ^ j);
          f[i][j][2] = f[i - 1][j][1] + (s[i] ^ j);
        }
      }
      if (t[1] == t[2]) {
        for (int j = 0; j < 2; j++) {
          for (int k = 1; k < 3; k++) {
            if (j != t[1]) ans = min(ans, f[n][j][k]);
          }
        }
      } else {
        for (int j = 0; j < 2; j++) {
          for (int k = 1; k < 3; k++) {
            if (j != t[1] || k + 1 < 3) ans = min(ans, f[n][j][k]);
          }
        }
      }
    }
  }
  putint(ans, '\n');
}

int main() {
  int T = getint();
  while (T--) solve();
  bufo.flush();
  return 0;
}