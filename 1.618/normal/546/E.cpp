#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
#define maxV 207
const int inf = 0x3f3f3f3f;
struct edge{
  int to, cap, rev;
};
vector <edge> adj[maxV];
int lev[maxV], iter[maxV];
void addEdge(int u, int v, int c){
  adj[u].push_back((edge){v, c, (int)adj[v].size()});
  adj[v].push_back((edge){u, 0, (int)adj[u].size() - 1});
}
void bfs(int s){
  memset(lev, 0x3f, sizeof(lev));
  lev[s] = 0;
  queue<int> que;
  que.push(s);
  while(!que.empty()){
    int u = que.front(); que.pop();
    for(int i = 0;i < (int)adj[u].size();i++){
      edge &e = adj[u][i];
      if(e.cap && lev[u] + 1 < lev[e.to]){
        lev[e.to] = lev[u] + 1;
        que.push(e.to);
      }
    }
  }
}
int dfs(int u, int t, int f){
  if(u == t) return f;
  int b = 0;
  for(int &i = iter[u];i < (int)adj[u].size();i++){
    edge &e = adj[u][i];
    if(e.cap && lev[u] < lev[e.to]){
      int flow = dfs(e.to, t, min(f - b, e.cap));
      b += flow;
      e.cap -= flow;
      adj[e.to][e.rev].cap += flow;
      if(b == f) return f;
    }
  }
  return b;
}
int dinic(int s, int t){
  int res = 0;
  while(true){
    bfs(s);
    if(lev[t] == inf) return res;
    memset(iter, 0, sizeof(iter));
    res += dfs(s, t, inf);
  }
}
#define maxn 105
int n, m, suma, a[maxn], sumb, b[maxn], ans[maxn][maxn];

int main(){
  n = getint(), m = getint();
  int S = 0, T = ((n << 1) | 1);
  for(int i = 1;i <= n;i++){
    suma += (a[i] = getint());
    addEdge(S, i, a[i]);
    addEdge(i, n + i, 100);
  }
  for(int i = 1;i <= n;i++){
    sumb += (b[i] = getint());
    addEdge(n + i, T, b[i]);
  }
  for(int i = 1;i <= m;i++){
    int u = getint(), v = getint();
    addEdge(u, n + v, 100);
    addEdge(v, n + u, 100);
  }
  if(suma ^ sumb){
    puts("NO");
    return 0;
  }
  suma -= dinic(S, T);
  if(suma){
    puts("NO");
    return 0;
  }
  puts("YES");
  for(int u = 1;u <= n;u++){
    for(int i = 0;i < (int)adj[u].size();i++){
      edge &e = adj[u][i];
      if(e.to > n) ans[u][e.to - n] = 100 - e.cap;
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
    }
  }
  
  return 0;
}