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

#define maxn 100005
int n, a, b, da, db, dis[maxn];
vector<int> adj[maxn];

void dfs(int u, int f) {
  for (auto v : adj[u]) {
    if (v == f) continue;
    dis[v] = dis[u] + 1;
    dfs(v, u);
  }
}

bool solve() {
  n = getint(), a = getint(), b = getint(), da = getint(), db = getint();
  for (int i = 1; i <= n; i++) adj[i].clear();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dis[a] = 0;
  dfs(a, 0);
  if (dis[b] <= da || da * 2 >= db) return true;
  int u = 1;
  for (int i = 2; i <= n; i++) if (dis[i] > dis[u]) u = i;
  dis[u] = 0;
  dfs(u, 0);
  int d = *max_element(dis + 1, dis + n + 1);
  return (d + 1) / 2 <= da;
}

int main() {
  int t = getint();
  while (t--) puts(solve() ? "Alice" : "Bob");
  bufo.flush();
  return 0;
}