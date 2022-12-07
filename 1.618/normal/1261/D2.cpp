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
#define mod 998244353
ll n,k,h[maxn],fct[maxn],x;
ll modpow(ll a,ll b){
  ll res = 1;
  while(b){
    if(b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
ll inv(ll a){
  return modpow(a,mod - 2);
}
ll c(ll a,ll b){
  return fct[a] * inv(fct[b]) % mod * inv(fct[a - b]) % mod;
}
int main(){
  n = getll(), k = getll();
  for(int i = 1;i <= n;i++) h[i] = getll();
  h[n + 1] = h[1];
  for(int i = 1;i <= n;i++) x += (h[i] != h[i + 1]);
  if(k == 1){
    puts("0");
    return 0;
  }
  fct[0] = 1;
  for(int i = 1;i <= n;i++) fct[i] = (ll)fct[i - 1] * i % mod;
  ll ans = 0;
  for(int y = 0;2 * y <= x;y++){
    ans = (ans + c(x,y) * c(x - y,y) % mod * modpow(k - 2,x - 2 * y)) % mod;
  }
  ans = ans * modpow(k,n - x) % mod;
  ll ans0 = (modpow(k,n) - ans + mod) % mod;
  ans0 = ans0 * inv(2) % mod;
  putll(ans0,'\n');
  bufo.flush();
  return 0;
}