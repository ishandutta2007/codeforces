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
#define maxn 200005
#define mp make_pair
typedef pair<int,ll> P;
int t,n,k;
ll siz[maxn],G,B;
vector <P> adj[maxn];// to,cst.
void dfs(int u,int f){
  siz[u] = 1;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i].first; ll w = adj[u][i].second;
    if(v == f) continue;
    dfs(v,u);
    siz[u] += siz[v];
    if(siz[v] & 1) G += w;
    B += min(siz[v],n - siz[v]) * w;
  }
}
int main(){
  t = getint();
  while(t--){
    G = B = 0;
    k = getint();
    n = (k << 1);
    for(int i = 1;i <= n;i++) adj[i].clear();
    for(int i = 1;i < n;i++){
      int u = getint(), v = getint(); ll w = getll();
      adj[u].push_back(mp(v,w));
      adj[v].push_back(mp(u,w));
    }
    dfs(1,-1);
    printf("%lld %lld\n",G,B);
  }
  return 0;
}