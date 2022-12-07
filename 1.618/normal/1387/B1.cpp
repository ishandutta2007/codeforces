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
#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
int n, rt, deg[maxn];
vector<int> adj[maxn];
int findRt() {
  for (int i = 1; i <= n; i++) {
    for (auto v : adj[i]) {
      if (deg[v] == 1) return i;
    }
  }
}
int par[maxn], dep[maxn];
void dfs(int u, int f) {
  par[u] = f;
  dep[u] = dep[f] + 1;
  for (auto v : adj[u]) {
    if (v != f) dfs(v, u);
  }
}
bool del[maxn];
int ans[maxn], tot;
int main() {
  n = getint();
  for (int i = 1; i < n; i++) {
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++deg[u], ++deg[v];
  }
  if (n == 2) {
    printf("2\n2 1\n");
    return 0;
  }
  rt = findRt();
  dfs(rt, 0);
  priority_queue<P> que;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) que.push(mp(dep[i], i));
  }
  while (!que.empty()) {
    P p = que.top(); que.pop();
    if (del[p.second]) continue;
    int u = par[p.second];
    vector<int> lis;
    for (auto v : adj[u]) {
      if (!del[v] && v != par[u]) lis.push_back(v);
    }
    tot += 2 * lis.size();
    lis.push_back(u);
    for (int i = 0; i + 1 < (int)lis.size(); i++) {
      ans[lis[i]] = lis[i + 1];
    }
    ans[lis.back()] = lis.front();
    for (auto v : lis) del[v] = true;
    if (par[u]) deg[par[u]]--;
    if (deg[par[u]] == 1) que.push(mp(dep[par[u]], par[u]));
  }
  putint(tot, '\n');
  for (int i = 1; i <= n; i++) putint(ans[i], i == n ? '\n' : ' ');
  bufo.flush();
  return 0;
}