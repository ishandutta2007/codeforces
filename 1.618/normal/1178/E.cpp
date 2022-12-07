#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 1000005
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
inline void putint(int x){
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
}
inline void putll(ll x){
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
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
char s[maxn],res[maxn];
int n,m;
void work(int l,int r){
  if(l > r) return;
  if(r - l <= 2){
    res[m++] = s[l];
    return;
  }
  if(s[l] == s[r]){
    res[m++] = s[l];
    work(l + 1,r - 1);
    res[m++] = s[r];
  }else if(s[l + 1] == s[r]){
    res[m++] = s[l + 1];
    work(l + 2,r - 1);
    res[m++] = s[r];
  }else if(s[l] == s[r - 1]){
    res[m++] = s[l];
    work(l + 1,r - 2);
    res[m++] = s[r - 1];
  }else if(s[l + 1] == s[r - 1]){
    res[m++] = s[l + 1];
    work(l + 2,r - 2);
    res[m++] = s[r - 1];
  }
}
int main(){
  scanf("%s",s + 1);
  n = strlen(s + 1);
  work(1,n);
  printf("%s\n",res);
  return 0;
}