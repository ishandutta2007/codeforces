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
#define mp make_pair
typedef pair<int,int> P;
const ll infll = 0x3f3f3f3f3f3f3f3fll;
int n,m;
P a[maxn],b[maxn << 1]; // val,id.
ll cst[maxn + 1];
int ans[maxn];
inline void range_add(int l,int r,ll x){
  if(l > r) return;
  cst[l] += x;
  if(r <= n) cst[r + 1] -= x;
}
int main(){
  m = getint(), n = getint();
  for(int i = 1;i <= n;i++){
    a[i].first = getint();
    a[i].second = i;
  }
  sort(a + 1,a + n + 1);
  int delta = a[1].first - 1;
  for(int i = 1;i <= n;i++) a[i].first -= delta;
  for(int i = 1;i <= n;i++){
    b[i].first = (getint() - delta + m) % m;
    if(!b[i].first) b[i].first = m;
    if(2 * (b[i].first - 1) >= m) b[n + i].first = b[i].first - m;
    else b[n + i].first = b[i].first + m;
    b[i].second = b[n + i].second = i;
  }
  sort(b + 1,b + (n << 1) + 1);
  //contribution of a.
  //time 1: [1,n]
  //time 2: [2,n + 1]
  //...
  //time n + 1: [n + 1,2n]
  for(int i = 1;i <= n;i++){
    //[i,i + n]
    int pos = lower_bound(b + i,b + i + n + 1,mp(a[i].first,0)) - b - i;
    range_add(1,pos,a[i].first);
    range_add(pos + 1,n + 1,-a[i].first);
  }
  //contribution of b.
  for(int i = 1;i <= n;i++){
    //[1,i]
    //time 1: b[i] with a[i]
    //time 2: b[i] with a[i - 1]
    //...
    //time i: b[i] with a[1]
    int pos = upper_bound(a + 1,a + i + 1,mp(b[i].first,n + 1)) - a;
    range_add(i + 1 - (pos - 1),i,b[i].first);
    range_add(1,i + 1 - pos,-b[i].first);
  }
  for(int i = n + 1;i <= (n << 1);i++){
    //[i - n + 1,n + 1]
    //time i - n + 1: n
    //t + a = i + 1
    int pos = upper_bound(a + i - n,a + n + 1,mp(b[i].first,n + 1)) - a;
    range_add(i + 1 - (pos - 1),n + 1,b[i].first);
    range_add(i - n + 1,i + 1 - pos,-b[i].first);
  }
  //prefix sum
  ll res = infll, st = 0;
  for(int i = 1;i <= n + 1;i++){
    cst[i] += cst[i - 1];
    if(res > cst[i]){
      res = cst[i];
      st = i;
    }
  }
  for(int i = 1;i <= n;i++) ans[a[i].second] = b[st + i - 1].second;
  putll(res,'\n');
  for(int i = 1;i <= n;i++) putint(ans[i],i == n ? '\n' : ' ');
  bufo.flush();
  return 0;
}