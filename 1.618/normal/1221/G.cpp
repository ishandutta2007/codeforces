//CF 1221G
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <map>

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
#define maxn 45
int n,m;
ll adj[maxn];
map <ll,ll> memo;
ll work(ll S){// independent set.
  if(!S) return 1;
  if(memo.find(S) != memo.end()) return memo[S];
  int u = __builtin_ctzll(S);
  return memo[S] = work(S & (S - 1)) + work(S & ~adj[u]);
}
int col[maxn];
bool dfs(int u){// bipartite
  for(int v = 0;v < n;v++){
    if(u != v && adj[u] & (1ll << v)){
      if(col[v] == col[u]) return false;
      if(col[v] == 0){
        col[v] = -col[u];
        if(!dfs(v)) return false;
      }
    }
  }
  return true;
}
int siz;
void flood(int u){
  col[u] = 1, siz++;
  for(int v = 0;v < n;v++){
    if(u != v && adj[u] & (1ll << v) && !col[v]) flood(v);
  }
}
int main(){
  n = getint(), m = getint();
  for(int i = 1;i <= m;i++){
    int u = getint() - 1, v = getint() - 1;
    adj[u] |= (1ll << v), adj[v] |= (1ll << u);
  }
  for(int i = 0;i < n;i++) adj[i] |= (1ll << i);
  ll ans = (1ll << n);
  ans -= work((1ll << n) - 1) * 2;
  ll bipart = 1;
  for(int i = 0;i < n;i++){
    if(!col[i]){
      col[i] = 1;
      if(dfs(i)) bipart <<= 1ll;
      else bipart = 0;
    }
  }
  ans += bipart;
  memset(col,0,sizeof(col));
  int num1 = 0, num2 = 0;
  for(int i = 0;i < n;i++){
    if(!col[i]){
      siz = 0;
      flood(i);
      if(siz == 1) num1++;
      else num2++;
    }
  }
  if(num2 == 0){
    putll(0,'\n');
  }else{
    ans -= 1ll << (num1 + num2);
    ans += 2 * (1ll << num1);
    putll(ans,'\n');
  }
  bufo.flush();
  return 0;
}