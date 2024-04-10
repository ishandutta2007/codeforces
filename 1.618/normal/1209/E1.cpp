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
#define maxmn 405
int t,n,m,ans;
struct Element{
  int r,c,val;
  bool operator < (const Element &b)const
  {
    return val > b.val;
  }
}a[maxmn];
int chosen[5];
bool check(){
  int r1 = a[chosen[0]].r, c1 = a[chosen[0]].c, d1, n1 = 0;
  int c2 = -1, r2 = -1, d2, n2 = 0;
  for(int i = 1;i <= 3;i++){
    if(a[chosen[i]].c != c1){
      c2 = a[chosen[i]].c;
      r2 = a[chosen[i]].r;
      break;
    }
  }
  if(c2 == -1) return true;
  for(int i = 0;i <= 3;i++){
    if(a[chosen[i]].c == c1) n1++;
    else if(a[chosen[i]].c == c2) n2++;
    else return true;
  }
  if(max(n1,n2) > 2) return true;
  for(int i = 0;i <= 3;i++){
    if(a[chosen[i]].c == c1 && a[chosen[i]].r != r1)
      d1 = abs(a[chosen[i]].r - r1);
    if(a[chosen[i]].c == c2 && a[chosen[i]].r != r2)
      d2 = abs(a[chosen[i]].r - r2);
  }
  if(d1 == 2 && d2 == 2) return true;
  if(d1 == 2 || d2 == 2) return false;
  return true;
}
void solve(){
  ans = 0;
  n = getint(), m = getint();
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      a[i * m + j].val = getint();
      a[i * m + j].r = i, a[i * m + j].c = j;
    }
  }
  sort(a,a + n * m);
  if(n <= 3 || m == 1){
    int res = 0;
    for(int i = 0;i < n;i++) res += a[i].val;
    putint(res,'\n');
    return;
  }
  #define i chosen[0]
  #define j chosen[1]
  #define k chosen[2]
  #define l chosen[3]
  for(i = 0;i <= 5;i++){
    for(j = i + 1;j <= 5;j++){
      for(k = j + 1;k <= 5;k++){
        for(l = k + 1;l <= 5;l++){
          if(check())
            ans = max(ans,a[i].val + a[j].val + a[k].val + a[l].val);
        }
      }
    }
  }
  #undef i
  #undef j
  #undef k
  #undef l
  putint(ans,'\n');
}
int main(){
  t = getint();
  while(t--) solve();
  bufo.flush();
  return 0;
}