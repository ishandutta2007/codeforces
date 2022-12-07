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
#define maxn 2005
#define mod 998244353
int n,k,h[maxn],f[maxn][maxn << 1];
// f[i][j + maxn] = real_f[i][j].
int main(){
  n = getint(), k = getint();
  for(int i = 1;i <= n;i++) h[i] = getint();
  h[n + 1] = h[1];
  f[0][0 + maxn] = 1;
  for(int i = 1;i <= n;i++){
    for(int j = -n;j <= n;j++){
      if(h[i] == h[i + 1]){
        f[i][j + maxn] = (ll)f[i - 1][j + maxn] * k % mod;
      }else{
        f[i][j + maxn] = (ll)f[i - 1][j + maxn] * (k - 2) % mod;
        f[i][j + maxn] = (f[i][j + maxn] + f[i - 1][j + 1 + maxn]) % mod;
        f[i][j + maxn] = (f[i][j + maxn] + f[i - 1][j - 1 + maxn]) % mod;
      }
    }
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++) (ans += f[n][i + maxn]) %= mod;
  putll(ans,'\n');
  bufo.flush();
  return 0;
}