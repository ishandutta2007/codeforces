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

#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;

int n, siz[maxn];
vector<P> adj[maxn];
bool col[maxn];

void paint(int u, int f) {
  for (auto e : adj[u]) {
    int v = e.first, w = e.second;
    if (v == f) continue;
    paint(v, u);
    if (w == 2) siz[v] = col[v] = 1;
  }
}

void calc(int u, int f) {
  for (auto e : adj[u]) {
    int v = e.first;
    if (v == f) continue;
    calc(v, u);
    siz[u] += siz[v];
  }
}

int main() {
  n = getint();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint(), w = getint();
    adj[u].push_back(mp(v, w));
    adj[v].push_back(mp(u, w));
  }
  paint(1, 0);
  calc(1, 0);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (col[i] && siz[i] == 1) ans.push_back(i); 
  }
  putint(ans.size(), '\n');
  for (auto v : ans) putint(v, ' ');
  bufo.flush();
  return 0;
}