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
#define maxn 100005
#define maxc 455
int n, B, m, q;
vector <int> adj[maxn];
int rt[maxn], siz[maxn], in[maxn], out[maxn];
// rt: root, out: , in: 
vector <int> lens[maxn]; vector <ll> sufSum[maxn];
void dfsIn(int u,int f){
  rt[u] = f ? rt[f] : u;
  siz[u] = 1;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == f) continue;
    dfsIn(v,u);
    siz[u] += siz[v];
    in[u] = max(in[u],in[v] + 1);
  }
}
void dfsOut(int u,int f){
  int maxIn = 0, maxNode = 0, maxIn2 = 0;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == f) continue;
    out[v] = out[u] + 1;
    if(in[v] + 1 > maxIn){
      maxIn2 = maxIn;
      maxIn = in[v] + 1;
      maxNode = v;
    }else if(in[v] + 1 > maxIn2){
      maxIn2 = in[v] + 1;
    }
  }
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == f) continue;
    if(v == maxNode) out[v] = max(out[v],maxIn2 + 1);
    else out[v] = max(out[v],maxIn + 1);
    dfsOut(v,u);
  }
}
ll f[maxc][maxc]; int c,id[maxn];
ll calc(int u,int v){
  if(f[id[u]][id[v]]) return f[id[u]][id[v]];
  if(siz[u] > siz[v]) swap(u,v);
  ll tmp_d = max(lens[u].back(),lens[v].back()), res = 0;
  for(int i = 0;i < (int)lens[u].size();i++){
    int a = lens[u][i];
    int pos = lower_bound(lens[v].begin(),lens[v].end(),tmp_d - a - 1)
              - lens[v].begin();
    res += pos * tmp_d + ll(siz[v] - pos) * (a + 1) + sufSum[v][pos];
  }
  if(siz[u] > B) f[id[u]][id[v]] = f[id[v]][id[u]] = res;
  return res;
}
int main(){
  n = getint(), m = getint(), q = getint();
  B = int(sqrt(n / 2.0));
  for(int i = 1;i <= m;i++){
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1;i <= n;i++){
    if(!rt[i]){
      dfsIn(i,0);
      if(siz[i] > B) id[i] = ++c;
      dfsOut(i,0);
    }
    lens[rt[i]].push_back(max(in[i],out[i]));
  }
  for(int i = 1;i <= n;i++)
    if(rt[i] == i){
      sort(lens[i].begin(),lens[i].end());
      sufSum[i].resize(siz[i]);
      sufSum[i].back() = lens[i].back();
      for(int j = siz[i] - 2;j >= 0;j--)
        sufSum[i][j] = lens[i][j] +  sufSum[i][j + 1];
    }
  for(int i = 1;i <= q;i++){
    int u = rt[getint()], v = rt[getint()];
    if(u == v) printf("-1\n");
    else printf("%.10f\n",(double)calc(u,v) / siz[u] / siz[v]);
  }
  return 0;
}