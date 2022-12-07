#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>

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
const ll mod = 998244353ll;
typedef set<int>::iterator Ite;
ll modpow(ll x,ll y){
  ll res = 1;
  while(y){
    if(y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
ll inv(ll x){
  return modpow(x,mod - 2);
}
int n,q;
ll prod_p[maxn];
inline ll pi(int l,int r){// p[l] * p[l + 1] * ... * p[r].
  return prod_p[r] * inv(prod_p[l - 1]) % mod;
}
set <int> ckps;
struct Sgt{
  ll sum[maxn << 2],mul[maxn << 2];
  void up(int id){
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
    (sum[id] *= mul[id]) %= mod;
  }
  void down(int id){
    if(mul[id] != 1){
      (mul[id << 1] *= mul[id]) %= mod;
      (sum[id << 1] *= mul[id]) %= mod;
      (mul[id << 1 | 1] *= mul[id]) %= mod;
      (sum[id << 1 | 1] *= mul[id]) %= mod;
      mul[id] = 1;
    }
  }
  void build(int id,int l,int r){
    mul[id] = 1;
    if(l == r){
      sum[id] = inv(pi(l,n));
    }else{
      int mid = (l + r) >> 1;
      build(id << 1,l,mid);
      build(id << 1 | 1,mid + 1,r);
      up(id);
    }
  }
  void multiply(int id,int l,int r,int ql,int qr,ll x){
    if(ql <= l && r <= qr){
      (mul[id] *= x) %= mod;
      (sum[id] *= x) %= mod;
    }else{
      down(id);
      int mid = (l + r) >> 1;
      if(ql <= mid) multiply(id << 1,l,mid,ql,qr,x);
      if(mid < qr) multiply(id << 1 | 1,mid + 1,r,ql,qr,x);
      up(id);
    }
  }
  ll sumall(){ return sum[1]; }
}sgt;
int main(){
  n = getint(), q = getint();
  for(int i = 1;i <= n;i++){
    prod_p[i] = getll() * inv(100) % mod;
  }
  prod_p[0] = 1;
  for(int i = 1;i <= n;i++) (prod_p[i] *= prod_p[i - 1]) %= mod;
  ckps.insert(1);
  ckps.insert(n + 1);
  sgt.build(1,1,n);
  
//  cout << sgt.sumall() << endl;
//  system("pause");
  
  for(int i = 1;i <= q;i++){
    int u = getint();
    Ite it = ckps.lower_bound(u);
    if(*it == u){
      Ite itl = it, itr = it; itl--, itr++;
      sgt.multiply(1,1,n,*itl,u - 1,inv(pi(u,*itr - 1)));
      ckps.erase(u);
    }else{
      Ite itl = it; itl--;
      sgt.multiply(1,1,n,*itl,u - 1,pi(u,*it - 1));
      ckps.insert(u);
    }
    putll(sgt.sumall(),'\n');
  }
  bufo.flush();
  return 0;
}