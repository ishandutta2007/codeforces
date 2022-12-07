#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() {
    it = len = 0;
  }
  char get() {
    if(it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get();c == ' ' || c == '\n' || c == '\r';c = get());
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush() {
    fwrite(s, 1, it, stdout);
  }
}buff, bufo;
inline int getint() {
  char c; int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get()) if(c == '-') sig = -1;
  for (;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
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
#define maxn 1005
#define maxm 1005
int n, m, x, y;
double a[maxm][maxm], E[maxn][maxm];
void gauss(int r) {
  for (int i = 1; i < m; i++) {
    double rate = a[i + 1][i] / a[i][i];
    a[i + 1][i] = 0;
    a[i + 1][i + 1] -= rate * a[i][i + 1];
    a[i + 1][m + 1] -= rate * a[i][m + 1];
  }
  E[r][m] = a[m][m + 1] / a[m][m];
  for (int i = m - 1; i >= 1; i--) {
    E[r][i] = (E[r][i + 1] + a[i][m + 1]) / a[i][i];
  }
}
void work(int r) {
  a[1][1] = 2, a[1][2] = -1, a[1][m + 1] = E[r + 1][1] + 3;
  for (int i = 2; i < m; i++) {
    a[i][i] = 3, a[i][i - 1] = a[i][i + 1] = -1;
    a[i][m + 1] = E[r + 1][i] + 4;
  }
  a[m][m] = 2, a[m][m - 1] = -1, a[m][m + 1] = E[r + 1][m] + 3;
  gauss(r);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (m == 1) {
    printf("%.10f\n", 2.0 * (n - x));
    return 0;
  }
  for (int i = n - 1; i >= x; i--) work(i);
  printf("%.10f\n", E[x][y]);
  return 0;
}