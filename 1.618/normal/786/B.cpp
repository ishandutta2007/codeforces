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
typedef pair<ll,int> Pli;
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
#define maxn 100005
#define mp make_pair
const ll infll = 0x3f3f3f3f3f3f3f3fll;
int n,q,s,root[2],V,lc[maxn * 3],rc[maxn * 3];
struct edge{
  int to,cst;
};
vector <edge> adj[maxn * 3];
int build(int l,int r,bool in){
  if(l == r) return l;
  int mid = (l + r) >> 1, id = ++V;
  if(in){
    adj[id].push_back((edge){build(l,mid,in),0});
    adj[id].push_back((edge){build(mid + 1,r,in),0});
  }else{
    lc[id] = build(l,mid,in);
    adj[lc[id]].push_back((edge){id,0});
    rc[id] = build(mid + 1,r,in);
    adj[rc[id]].push_back((edge){id,0});
  }
  return id;
}
void addedge(int id,int l,int r,int ql,int qr,int v,int w,bool in){
  if(ql <= l && r <= qr){
    if(in) adj[v].push_back((edge){id,w});
    else adj[id].push_back((edge){v,w});
  }else{
    int mid = (l + r) >> 1;
    if(ql <= mid){
      if(in) addedge(adj[id][0].to,l,mid,ql,qr,v,w,in);
      else addedge(lc[id],l,mid,ql,qr,v,w,in);
    }
    if(mid < qr){
      if(in) addedge(adj[id][1].to,mid + 1,r,ql,qr,v,w,in);
      else addedge(rc[id],mid + 1,r,ql,qr,v,w,in);
    }
  }
}
ll dis[maxn * 3];
int main(){
  n = getint(), q = getint(), s = getint();
  V = n;
  root[0] = build(1,n,true);
  root[1] = build(1,n,false);
  while(q--){
    int t = getint();
    if(t == 1){
      int u = getint(), v = getint(), w = getint();
      adj[u].push_back((edge){v,w});
    }else if(t == 2){
      int v = getint(), l = getint(), r = getint(), w = getint();
      addedge(root[0],1,n,l,r,v,w,true);
    }else{
      int v = getint(), l = getint(), r = getint(), w = getint();
      addedge(root[1],1,n,l,r,v,w,false);
    }
  }
  memset(dis,0x3f,sizeof(dis));
  dis[s] = 0;
  priority_queue <Pli,vector<Pli>,greater<Pli> > que;
  que.push(mp(0,s));
  while(!que.empty()){
    Pli p = que.top(); que.pop();
    if(dis[p.second] != p.first) continue;
    for(int i = 0;i < (int)adj[p.second].size();i++){
      edge e = adj[p.second][i];
      if(p.first + e.cst < dis[e.to]){
        dis[e.to] = p.first + e.cst;
        que.push(mp(dis[e.to],e.to));
      }
    }
  }
  for(int i = 1;i <= n;i++)
    putll(dis[i] == infll ? -1 : dis[i],i == n ? '\n' : ' ');
  bufo.flush();
  return 0;
}