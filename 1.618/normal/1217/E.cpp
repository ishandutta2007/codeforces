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
typedef unsigned int uint;
const uint uinf = 0x7f7f7f7fu;
int n,m,a[maxn];
uint res1,res2;
struct Sgt{
  uint min1[maxn << 2],min2[maxn << 2];
  void up(int id){
    if(min1[id << 1 | 1] < min1[id << 1]){
      min1[id] = min1[id << 1 | 1];
      min2[id] = min(min1[id << 1],min2[id << 1 | 1]);
    }else{
      min1[id] = min1[id << 1];
      min2[id] = min(min2[id << 1],min1[id << 1 | 1]);
    }
  }
  void build(int id,int l,int r,int digit){ //digit: 1,10,100,etc.
    if(l == r){
      if(a[l] / digit % 10) min1[id] = a[l];
      else min1[id] = uinf;
      min2[id] = uinf;
    }else{
      int mid = (l + r) >> 1;
      build(id << 1,l,mid,digit);
      build(id << 1 | 1,mid + 1,r,digit);
      up(id);
    }
  }
  void update(int id,int l,int r,int pos,uint x){
    if(l == r) min1[id] = x;
    else{
      int mid = (l + r) >> 1;
      if(pos <= mid) update(id << 1,l,mid,pos,x);
      else update(id << 1 | 1,mid + 1,r,pos,x);
      up(id);
    }
  }
  void query(int id,int l,int r,int ql,int qr){
    if(ql <= l && r <= qr){
      if(res1 < min1[id]) res2 = min(res2,min1[id]);
      else{
        res2 = min(res1,min2[id]);
        res1 = min1[id];
      }
      return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid) query(id << 1,l,mid,ql,qr);
    if(mid < qr) query(id << 1 | 1,mid + 1,r,ql,qr);
  }
}sgt[9];
int main(){
  n = getint(), m = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  for(int dig = 1;dig <= int(1e8);dig *= 10)
    sgt[int(log10(dig))].build(1,1,n,dig);
  for(int i = 1;i <= m;i++){
    int fl = getint(), x = getint(), y = getint();
    if(fl == 1){
      for(int dig = 1;dig <= int(1e8);dig *= 10){
        if(y / dig % 10) sgt[int(log10(dig))].update(1,1,n,x,y);
        else sgt[int(log10(dig))].update(1,1,n,x,uinf);
      }
    }else{
      uint ans = uinf;
      for(int i = 0;i <= 8;i++){
        res1 = res2 = uinf;
        sgt[i].query(1,1,n,x,y);
        ans = min(ans,res1 + res2);
      }
      if(ans == uinf) putint(-1,'\n');
      else putint(ans,'\n');
    }
  }
  bufo.flush();
  return 0;
}