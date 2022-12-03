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
inline void putint(int x) {
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

#define maxV 10107
#define mp make_pair
typedef pair<int, int> P;

namespace Graph {
  int V;
  struct Edge {
    int to, cap, cst, rev;
  };
  vector<Edge> adj[maxV];
  int h[maxV], dis[maxV], prvv[maxV], prve[maxV];
  
  void init(int n) {
    V = n;
    for (int i = 1; i <= V; i++) adj[i].clear();
  }
  void addEdge(int u, int v, int c, int d) {
    adj[u].push_back((Edge){v, c, d, (int)adj[v].size()});
    adj[v].push_back((Edge){u, 0, -d, (int)adj[u].size() - 1});
  }
  
  int minCostFlow(int s, int t, int f) {
    int res = 0;
    while (f > 0) {
      memset(dis, 0x3f, sizeof(dis));
      priority_queue<P, vector<P>, greater<P>> que;
      dis[s] = 0;
      que.push(mp(0, s));
      while (!que.empty()) {
        P p = que.top(); que.pop();
        int u = p.second;
        if (p.first != dis[u]) continue;
        for (int i = 0; i < (int)adj[u].size(); i++) {
          Edge &e = adj[u][i];
          if (e.cap && dis[u] + h[u] + e.cst - h[e.to] < dis[e.to]) {
            dis[e.to] = dis[u] + h[u] + e.cst - h[e.to];
            prvv[e.to] = u;
            prve[e.to] = i;
            que.push(mp(dis[e.to], e.to));
          }
        }
      }
      for (int i = 1; i <= V; i++) h[i] += dis[i];
      int flow = f;
      for (int i = t; i != s; i = prvv[i]) {
        chmin(flow, adj[prvv[i]][prve[i]].cap);
      }
      f -= flow;
      res += flow * h[t];
      for (int i = t; i != s; i = prvv[i]) {
        Edge &e = adj[prvv[i]][prve[i]];
        e.cap -= flow;
        adj[e.to][e.rev].cap += flow;
      }
    }
    return res;
  }
}

#define maxn 105
int n, m, a[maxn][maxn], b[maxn][maxn];

int main() {
  n = getint();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = 2;
    }
  }
  m = getint();
  for (int i = 1; i <= m; i++) {
    int u = getint(), v = getint();
    a[u][v] = 1;
    a[v][u] = 0;
  }
  int s = n * (n + 1) / 2 + 1, t = s + 1;
  Graph::init(t);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int u = (n + n - i) * (i - 1) / 2 + j - i + n;
      if (a[i][j]) Graph::addEdge(u, i, 1, 0);
      if (a[j][i]) Graph::addEdge(u, j, 1, 0);
      Graph::addEdge(s, u, 1, 0);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int w = 0; w < n - 1; w++) {
      Graph::addEdge(i, t, 1, w);
    }
  }
  Graph::minCostFlow(s, t, n * (n - 1) / 2);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int u = (n + n - i) * (i - 1) / 2 + j - i + n;
      for (auto e : Graph::adj[u]) {
        if (e.to == i && !e.cap) b[i][j] = true;
        if (e.to == j && !e.cap) b[j][i] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      putint(b[i][j]);
    }
    bufo.put('\n');
  }
  bufo.flush();
  return 0;
}