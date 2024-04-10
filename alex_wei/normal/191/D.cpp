#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
inline void print(int x) {
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int N = 3e5 + 5;
int cnt = 1, hd[N], nxt[N << 1], to[N << 1];
void add(int u, int v) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;}
int deg[N], overlap[N];
int n, m, odd, ans;
int dn, dfn[N], low[N], top, stc[N];
void tarjan(int id, int ff, int e) {
  dfn[id] = low[id] = ++dn, stc[++top] = id;
  for(int i = hd[id]; i; i = nxt[i]) {
    int it = to[i];
    if(!dfn[it]) {
      tarjan(it, id, i);
      low[id] = min(low[id], low[it]);
      if(low[it] >= dfn[id]) {
        int node = 1, o = deg[id] > 2;
        for(int x = 0; x != it; ) node++, o += deg[x = stc[top--]] > 2;
        if((node > 2 || overlap[id]) && o <= 1) ans++;
      }
    }
    else {
      low[id] = min(low[id], dfn[it]);
      if((i >> 1) != (e >> 1) && it == ff) overlap[ff] = 1;
    }
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
  /*
  freopen("graph.in", "r", stdin);
  freopen("graph.out", "w", stdout);
  */
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    int u = read(), v = read();
    add(u, v), add(v, u);
    deg[u]++, deg[v]++;
  }
  tarjan(1, 0, 0);
  for(int i = 1; i <= n; i++) odd += deg[i] & 1;
  cerr << odd << endl;
  assert(odd & 1 ^ 1);
  cerr << ans << endl;
  cout << ans + odd / 2 << " " << m << endl;
  return 0;
}
/*
2022/6/9
zhapianti
*/