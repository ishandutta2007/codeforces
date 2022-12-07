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
#define maxn 15
#define maxm 2005
typedef pair<int,int> P;
int t,n,m,a[maxn][maxm],sum[4105],f[4105];
P c[maxn];//val,id.
void solve(){
  n = getint(), m = getint();
  const int U = (1 << n) - 1;
  for(int i = 0;i < m;i++) c[i].first = 0;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      a[i][j] = getint();
      c[j].first = max(c[j].first,a[i][j]);
    }
  }
  for(int i = 0;i < m;i++) c[i].second = i;
  sort(c,c + m,greater<P>());
  memset(f,0xc0,sizeof(f));
  f[0] = 0;
  for(int i = 0;i < min(m,n);i++){
    for(int S = 1;S < (1 << n);S++)
      sum[S] = sum[S & (S - 1)] + a[__builtin_ctz(S)][c[i].second];
    for(int S = 1;S < (1 << n);S++)
      for(int shift = 1;shift < n;shift++)
        sum[S] = max(sum[S],sum[(S << shift & U) | (S >> n - shift)]);
    for(int S = (1 << n) - 1;S >= 0;S--){
      for(int T = S;T;T = S & (T - 1)){
        f[S] = max(f[S],f[S & ~T] + sum[T]);
      }
    }
  }
  putint(f[(1 << n) - 1],'\n');
}
int main(){
  t = getint();
  while(t--) solve();
  bufo.flush();
  return 0;
}