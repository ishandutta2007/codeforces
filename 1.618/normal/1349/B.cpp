#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>

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
#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
typedef set<int>::iterator Ite;
int t, n, k; 
P a[maxn];
void solve() {
  n = getint(), k = getint();
  bool fd = false;
  for (int i = 1; i <= n; i++) {
    a[i].first = getint(), a[i].second = i;
    if (k == a[i].first) fd = true;
  }
  if (!fd) {
    puts("no");
    return;
  }
  if (n == 1) {
    puts("yes");
    return;
  }
  sort(a + 1, a + n + 1, greater<P>());
  set<int> S;
  S.insert(-100);
  S.insert(n + 100);
  for (int i = 1; i <= n; i++) {
    int x = a[i].second;
    Ite it = S.lower_bound(x);
    int d = *it - x;
    it--;
    d = min(d, x - *it);
    if (d <= 2) {
      if (k <= a[i].first) puts("yes");
      else puts("no");
      return;
    }
    S.insert(x);
  }
}
int main() {
  t = getint();
  while (t--) solve();
  return 0;
}