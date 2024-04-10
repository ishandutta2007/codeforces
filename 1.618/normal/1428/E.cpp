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

template<class T> bool chmin(T &x, T y) {
  return x > y ? (x = y, true) : false;
}

#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
typedef pair<ll, P> Plp;
const ll infll = 0x3f3f3f3f3f3f3f3f;

int n, k, a[maxn];
ll calc(int x, int y) { // xy, 1 <= y <= x.
  if (y > x) return infll;
  int q = x / y, r = x % y, num = (x - r) / q;
  return (ll)r * (q + 1) * (q + 1) + ll(num - r) * q * q;
}

int main() {
  n = getint(), k = getint();
  ll ans = 0;
  priority_queue<Plp> que;
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    ans += (ll)a[i] * a[i];
    que.push(mp(calc(a[i], 1) - calc(a[i], 2), mp(a[i], 1)));
  }
  for (int i = n + 1; i <= k; i++) {
    Plp p = que.top(); que.pop();
    int x = p.second.first, y = p.second.second;
    ans -= p.first;
    que.push(mp(calc(x, y + 1) - calc(x, y + 2), mp(x, y + 1)));
  }
  putll(ans, '\n');
  bufo.flush();
  return 0;
}