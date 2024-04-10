// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx", "avx2")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 2000005;
int n, m;

int vis[N], pr[N], pos[N], len;
void pre(int n) {
  pr[++len] = 1, pos[1] = 1; //  1  
  for (rint i = 2; i <= n; i++) {
    if (!vis[i]) pr[++len] = i, pos[i] = len;
    for (rint j = 1; j <= len && pr[j] * i <= n; j++) {
      vis[pr[j] * i] = 1;
      if (i % pr[j] == 0) break;
    }
  }
/*
  cerr << len << '\n';
  for (rint i = 1; i <= 5; i++) {
    printf("%d ", pr[i]);
  }
  puts("");
  system("pause");
*/
}
void sieve(int x, vector <int> &inc) {
  for (rint i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt ^= 1;
        x /= i;
      }
      if (cnt & 1) inc.push_back(pos[i]);
    }
  }
  if (x > 1) inc.push_back(pos[x]);
}

vector <int> adj[N];
void add(int u, int v) {
  u = pos[u], v = pos[v];
  adj[u].push_back(v);
}
int dis[N], inf = 1e9;
int bfs(int St) {
  fill(dis + 1, dis + len + 1, inf);
  fill(vis + 1, vis + len + 1, 0);
  //printf("%d\n", dis[0]);
  dis[St] = 0, vis[St] = 1;
  queue <pair <int, int>> q;
  while (!q.empty()) q.pop();
  q.push(make_pair(St, -1));
  int res = inf;
  while (!q.empty()) {
    pair <int, int> fir = q.front(); q.pop();
    int u = fir.first, fa = fir.second;
    //printf("%d %d\n", u, fa);
    for (auto v: adj[u]) {
      if (v == fa) continue;
      if (!vis[v]) {
        vis[v] = 1;
        dis[v] = dis[u] + 1;
        q.push(make_pair(v, u));
        //printf("goto %d\n", v);
        //system("pause");
      } else {
        res = min(res, dis[u] + dis[v] + 1);
      }
    }
  }
  return res;
}

int main() {
  pre(1e6), n = read();
  for (rint i = 1; i <= n; i++) {
    int x = read();
    vector <int> inc;
    sieve(x, inc);
    if (inc.size() == 0) { // 1
      puts("1"); exit(0);
    }
    inc.push_back(1);
    //printf("%d: ", i);
    //for (auto v: inc) printf("%d ", v);
    //puts("");
    add(inc[1], inc[0]);
    add(inc[0], inc[1]);
  }
  
  int ans = 1e9;
  for (rint i = 1; pr[i] <= 1000; i++) {
    //printf("%d\n", i);
    ans = min(ans, bfs(i));
  }
  if (ans > n) ans = -1;
  printf("%d\n", ans);
  return 0;
}