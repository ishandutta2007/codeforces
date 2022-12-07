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
#define maxn 1000005
#define maxA 2097165
int n,a[maxn],maxa,f[maxA],g[maxA];
inline void update(int x,int cur){//f[x] -> cur?
  if(cur > f[x]) g[x] = f[x], f[x] = cur;
  else g[x] = max(g[x],cur);
}
inline int firstbit(int x){
  if(!x) return 0;
  return 1 << (31 - __builtin_clz(x));
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    a[i] = getint();
    maxa = max(maxa,a[i]);
  }
  for(int i = n;i >= 1;i--) update(a[i],i);
  for(int i = 0;i <= 20;i++){
    for(int j = 0;j <= maxa;j++){
      if(~j & (1 << i)){
        update(j,f[j ^ (1 << i)]);
        update(j,g[j ^ (1 << i)]);
      }
    }
  }
  int ans = 0;
  for(int i = 1;i <= n - 2;i++){
    int res = 0, tmp = (~a[i] & 0x1fffff);
    for(int j = firstbit(tmp);j;tmp ^= j, j = firstbit(tmp))
      if(g[res | j] > i) res |= j;
    ans = max(ans,res | a[i]);
  }
  putint(ans,'\n');
  bufo.flush();
  return 0;
}