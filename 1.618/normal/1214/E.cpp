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
#define maxn 100005
#define mp make_pair
typedef pair<int,int> P;
int n;
P d[maxn];//dis,id.
int core[maxn << 1],k;
int u[maxn << 1],v[maxn << 1],E;
void addedge(int a,int b){
  u[++E] = a;
  v[E] = b;
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) d[i].first = getint(), d[i].second = i;
  sort(d + 1,d + n + 1,greater<P>());
  for(k = 1;k <= n;k++){
    core[k] = (d[k].second << 1) - 1;
    if(k > 1) addedge(core[k - 1],core[k]);
  }
  k = n;
  for(int i = 1;i <= n;i++){
    if(d[i].first == k - i + 1){
      core[++k] = (d[i].second << 1);
      addedge(core[k - 1],core[k]);
    }else{
      addedge(core[i + d[i].first - 1],d[i].second << 1);
    }
  }
  for(int i = 1;i <= E;i++){
    putint(u[i],' ');
    putint(v[i],'\n');
  }
  bufo.flush();
  return 0;
}