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
#define maxn 5005
#define maxm 5005
int n,m,deg[maxn],u[maxm],v[maxm];
vector <int> adj[maxn];

int main(){
  n = getint(), m = getint();
  for(int i = 1;i <= m;i++){
    u[i] = getint(), v[i] = getint();
    adj[u[i]].push_back(v[i]);
    ++deg[v[i]];
  }
  queue <int> que;
  for(int i = 1;i <= n;i++){
    if(!deg[i]) que.push(i);
  }
  int cnt = 0;
  while(!que.empty()){
    int from = que.front(); que.pop();
    cnt++;
    for(int i = 0;i < (int)adj[from].size();i++){
      int to = adj[from][i];
      --deg[to];
      if(!deg[to]) que.push(to);
    }
  }
  if(cnt == n){
    putint(1,'\n');
    for(int i = 1;i <= m;i++) putint(1,i == m ? '\n' : ' ');
  }else{
    putint(2,'\n');
    for(int i = 1;i <= m;i++)
      putint(u[i] < v[i] ? 1 : 2,i == m ? '\n' : ' ');
  }
  bufo.flush();
  return 0;
}