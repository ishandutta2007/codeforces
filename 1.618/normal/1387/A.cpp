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
}buff;
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
#define maxn 100005
#define mp make_pair
typedef pair<int, int> P;
const double EPS = 1e-10;
struct Linear {
  int k, b;
  Linear operator + (Linear g) {
    return (Linear){k + g.k, b + g.b};
  }
  Linear operator - (Linear g) {
    return (Linear){k - g.k, b - g.b};
  }
  bool null() {
    return k == 0 && b == 0;
  }
  double eq(double y) {
    return 1.0 * (y - b) / k;
  }
  double at(double x) {
    return k * x + b;
  }
}f[maxn];
int n, m;
vector<P> adj[maxn];
vector<int> lis;
void dfs(int u) {
  lis.push_back(u); 
  for (auto p : adj[u]) {
    int v = p.first, w = p.second;
    if (f[v].null()) {
      f[v] = (Linear){0, w} - f[u];
      dfs(v);
    }
  }
}
double a[maxn];
void work(int u) {
  lis.clear();
  f[u] = (Linear){1, 0};
  dfs(u);
  double lb = -1e6, rb = 1e6;
  for (auto u : lis) {
    for (auto p : adj[u]) {
      int v = p.first, w = p.second;
      Linear sum = f[u] + f[v];
      if (sum.k == 0) {
        if (sum.b != w) {
          puts("NO");
          exit(0);
        }
      } else {
        double x = sum.eq(w);
        lb = max(lb, x);
        rb = min(rb, x);
      }
    }
  }
  if (lb > rb) {
    puts("NO");
    exit(0);
  }
  if (lb == rb) {
    for (auto u : lis) a[u] = f[u].at(lb);
    return;
  }
  vector<int> ps;
  for (auto u : lis) {
    if (f[u].k == -1) ps.push_back(f[u].b);
    else ps.push_back(-f[u].b);
  }
  sort(ps.begin(), ps.end());
  int cnt = lis.size();
  lb = ps[(cnt + 1) / 2 - 1];
  for (auto u : lis) a[u] = f[u].at(lb);
}
int main() {
  n = getint(), m = getint();
  for (int i = 1; i <= m; i++) {
    int u = getint(), v = getint(), w = getint();
    adj[u].push_back(mp(v, w));
    adj[v].push_back(mp(u, w));
  }
  for (int i = 1; i <= n; i++) {
    if (f[i].null()) work(i);
  }
  puts("YES");
  for (int i = 1; i <= n; i++)
    printf("%.2f%c", a[i], i == n ? '\n' : ' ');
  return 0;
}