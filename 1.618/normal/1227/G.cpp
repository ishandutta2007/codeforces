#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
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
#define maxn 1005
typedef pair<int,int> P;
int n;
P a[maxn]; // val,id.
int typ[maxn],st[maxn];
bool ans[maxn][maxn];
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    a[i].first = getint();
    a[i].second = i;
  }
  sort(a + 1,a + n + 1,greater<P>());
  for(int i = 1;i <= n + 1;i++) st[i] = typ[i] = 1;
  for(int i = 1;i <= n;i++){
    int col = a[i].second, sameid = -1;
    for(int j = n + 1;j >= 2;j--){
      if(typ[j] == typ[j - 1]){
        sameid = j;
        break;
      }
    }
    if(sameid == -1){
      for(int j = 1;j <= a[i].first;j++) ans[j][col] = 1;
    }else{
      if(a[i].first < sameid - st[sameid]){
        for(int j = st[sameid];j < st[sameid] + a[i].first;j++)
          ans[j][col] = 1;
      }else if(a[i].first < sameid){
        for(int j = sameid - 1;j >= sameid - a[i].first;j--)
          ans[j][col] = 1;
      }else{
        for(int j = 1;j < sameid;j++) ans[j][col] = 1;
        for(int j = sameid + 1;j <= a[i].first + 1;j++)
          ans[j][col] = 1;
      }
    }
    int j = 1,k;
    while(j <= n + 1){
      k = j + 1;
      while(k <= n + 1 && typ[k] == typ[j]) k++;
      k--;
      for(int l = j;l <= k;l++){
        if(l == j || ans[l][col] != ans[l - 1][col]){
          typ[l] = typ[l - 1] + 1;
          st[l] = l;
        }else{
          typ[l] = typ[l - 1];
          st[l] = st[l - 1];
        }
      }
      j = k + 1;
    }
  }
  putint(n + 1,'\n');
  for(int i = 1;i <= n + 1;i++){
    for(int j = 1;j <= n;j++) bufo.put('0' + ans[i][j]);
    bufo.put('\n');
  }
  bufo.flush();
  return 0;
}