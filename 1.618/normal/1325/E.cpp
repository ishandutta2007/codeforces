#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#include <map>

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
    for (c = get();c == ' ' || c == '\n';c = get());
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
  for (c = buff.get(); c == ' ' || c == '\n'; c = buff.get());
  return c;
}
#define maxp 78505
#define maxn 100005
#define maxa 1000005
int id[maxa], pri[maxp], k;
const int inf = 0x3f3f3f3f;
// id[997] = 168.
void sieve(int n) {
  id[1] = -1;
  for (int i = 2; i <= n; i++) {
    if (!id[i]) {
      pri[++k] = i;
      id[i] = k;
    }
    for (int j = 1; j <= k && pri[j] * i <= n; j++) {
      id[pri[j] * i] = -1;
      if (i % pri[j] == 0) break;
    }
  }
}
vector <int> adj[maxp];
bool app[maxp];
inline void addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool checkMulti() {
  for (int i = 0; i <= 168; i++) {
    memset(app, 0, sizeof(app));
    for (int j = 0; j < (int)adj[i].size(); j++) {
      if (app[adj[i][j]]) return true;
      app[adj[i][j]] = true;
    }
  }
  return false;
}
int dis[maxn], par[maxn];
int minCycle(int s) {
  int ans = inf;
  queue <int> que;
  memset(dis, 0x3f, sizeof(dis));
  par[s] = -1;
  dis[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (int i = 0;i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (dis[v] == inf) {
        par[v] = u;
        dis[v] = dis[u] + 1;
        que.push(v);
      } else if (v != par[u]) {
        ans = min(ans, dis[u] + dis[v] + 1);
      }
    }
  }
  return ans;
}
int n, a[maxn];
int main() {
  sieve(1000000);
  n = getint();
  bool self = false;
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    vector <int> fac;
    for (int j = 2; j * j <= a[i]; j++) {
      int e = 0;
      while (a[i] % j == 0) {
        e ^= 1;
        a[i] /= j;
      }
      if (e) fac.push_back(j);
    }
    if (a[i] > 1) fac.push_back(a[i]);
    if (fac.empty()) self = true;
    else if(fac.size() == 1) addEdge(0, id[fac.front()]);
    else addEdge(id[fac.front()], id[fac.back()]);
  }
  if (self) putint(1, '\n');
  else if (checkMulti()) putint(2, '\n');
  else {
    int ans = inf;
    for (int i = 0; i <= 168; i++) ans = min(ans, minCycle(i));
    putint(ans == inf ? -1 : ans, '\n');
  }
  bufo.flush();
  return 0;
}