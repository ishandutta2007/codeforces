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
#define maxn 1000005
const int inf = 0x3f3f3f3f;
int n,w;
ll s[maxn];
void range_add(int l,int r,ll x){
  s[l] += x;
  if(r < w) s[r + 1] -= x;
}
int a[maxn],deq[maxn],he,ta;
int main(){
  scanf("%d%d",&n,&w);
  for(int ii = 1;ii <= n;ii++){
    int l;
    scanf("%d",&l);
    for(int i = 1;i <= l;i++) scanf("%d",&a[i]);
    int len = w - l + 1;
    if(len <= l){
      he = ta = 0;
      for(int i = 1;i <= l;i++){
        while(he < ta && deq[he] <= i - len) he++;
        while(he < ta && a[deq[ta - 1]] <= a[i]) ta--;
        deq[ta++] = i;
        if(i < len) range_add(i,i,max(0,a[deq[he]]));
        else range_add(i,i,a[deq[he]]);
      }
      ll maxi = 0;
      for(int i = w;i > l;i--){
        maxi = max(maxi,(ll)a[i - len + 1]);
        range_add(i,i,maxi);
      }
    }else{
      ll maxi = 0;
      for(int i = 1;i < l;i++){
        maxi = max(maxi,(ll)a[i]);
        range_add(i,i,maxi);
      }
      maxi = max(maxi,(ll)a[l]);
      range_add(l,len,maxi);
      maxi = 0;
      for(int i = w;i > len;i--){
        maxi = max(maxi,(ll)a[i - len + 1]);
        range_add(i,i,maxi);
      }
    }
  }
  for(int i = 1;i <= w;i++){
    s[i] += s[i - 1];
    printf("%I64d%c",s[i],i == w ? '\n' : ' ');
  }
  return 0;
}