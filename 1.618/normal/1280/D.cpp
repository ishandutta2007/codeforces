#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
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
}buff,bufo;
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
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxn 3005
int t,n,m,w[maxn],siz[maxn];
ll f[maxn][maxn],g[maxn][maxn],tmpf[maxn],tmpg[maxn];
vector <int> adj[maxn];
void calc_siz(int u,int fa){
  siz[u] = 1;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == fa) continue;
    calc_siz(v,u);
    siz[u] += siz[v];
  }
}
void dp(int u,int fa){
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v != fa) dp(v,u);
  }
  f[u][1] = 0;
  g[u][1] = w[u];
  int cur = 1;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == fa) continue;
    memset(tmpf,0xc0,sizeof(tmpf));
    memset(tmpg,0xc0,sizeof(tmpg));
    for(int j = 1;j <= min(m,cur);j++){
      for(int k = 1;k <= min(m,siz[v]) && j + k - 1 <= m;k++){
        if(f[u][j] + f[v][k] + (g[v][k] > 0) > tmpf[j + k]){
          tmpf[j + k] = f[u][j] + f[v][k] + (g[v][k] > 0);
          tmpg[j + k] = g[u][j];
        }else if(f[u][j] + f[v][k] + (g[v][k] > 0) == tmpf[j + k]){
          tmpg[j + k] = max(tmpg[j + k],g[u][j]);
        }
        if(f[u][j] + f[v][k] > tmpf[j + k - 1]){
          tmpf[j + k - 1] = f[u][j] + f[v][k];
          tmpg[j + k - 1] = g[u][j] + g[v][k];
        }else if(f[u][j] + f[v][k] == tmpf[j + k - 1]){
          tmpg[j + k - 1] = max(tmpg[j + k - 1],g[u][j] + g[v][k]);
        }
      }
    }
    for(int j = 1;j <= min(m,cur + siz[v]);j++){
      f[u][j] = tmpf[j];
      g[u][j] = tmpg[j];
    }
    cur += siz[v];
  }
}
void solve(){
  memset(f,0xc0,sizeof(f));
  memset(g,0xc0,sizeof(g));
  calc_siz(1,0);
  dp(1,0);
  putll(f[1][m] + (g[1][m] > 0),'\n');
}
int main(){
  t = getint();
  while(t--){
    n = getint(), m = getint();
    for(int i = 1;i <= n;i++) adj[i].clear();
    for(int i = 1;i <= n;i++) w[i] = -getint();
    for(int i = 1;i <= n;i++) w[i] += getint();
    for(int i = 1;i < n;i++){
      int u = getint(), v = getint();
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    solve();
  }
  bufo.flush();
  return 0;
}