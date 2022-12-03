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
}buff;
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

#define maxn 105
#define mp make_pair
typedef pair<int, int> P;
int n, m, x[maxn];
vector<P> adj[maxn];

bool dfs(int u, int c) {
  x[u] = c;
  for (auto e : adj[u]) {
    int nei = e.second ? c : -c;
    if (!x[e.first] && !dfs(e.first, nei)) return false;
    if (c == x[e.first] && !e.second) return false;
    if (c != x[e.first] && e.second) return false;
  }
  return true;
}

int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= m; i++) {
    int u = getint(), v = getint(), w = getint();
    adj[u].push_back(mp(v, w));
    adj[v].push_back(mp(u, w));
  }
  for (int i = 1; i <= n; i++) {
    if (!x[i] && !dfs(i, 1)) {
      puts("Impossible");
      return 0;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) if (x[i] == 1) ans.push_back(i);
  printf("%d\n", (int)ans.size());
  for (auto i : ans) printf("%d ", i);
  puts("");
  return 0;
}