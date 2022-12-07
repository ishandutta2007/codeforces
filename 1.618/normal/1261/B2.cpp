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
const int maxlog = 17;
P a[maxn];
vector <P> qs[maxn]; // pos,id.
int n,m,val[maxn],bit[maxn],ans[maxn];
void add(int pos,int x){
  for(int i = pos;i <= n;i += i & -i) bit[i] += x;
}
int qsum(int pos){
  int res = 0;
  for(int i = pos;i;i -= i & -i) res += bit[i];
  return res;
}
int kth_1(int k){
  int pos = 1;
  for(int i = maxlog;i >= 0;i--){
    int ed = pos + (1 << i) - 1;
    if(ed <= n && bit[ed] < k){
      pos = ed + 1;
      k -= bit[ed];
    }
  }
  return pos;
}
bool cmp_pair(P x,P y){
  if(x.first == y.first) return x.second < y.second;
  return x.first > y.first;
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    val[i] = getint();
    a[i] = mp(val[i],i);
  }
  sort(a + 1,a + n + 1,cmp_pair);
  m = getint();
  for(int i = 1;i <= m;i++){
    int k = getint(), pos = getint();
    qs[k].push_back(mp(pos,i));
  }
  for(int k = 1;k <= n;k++){
    add(a[k].second,1);
    for(int i = 0;i < (int)qs[k].size();i++){
      int pos = qs[k][i].first;
      ans[qs[k][i].second] = val[kth_1(pos)];
    }
  }
  for(int i = 1;i <= m;i++) putint(ans[i],'\n');
  bufo.flush();
  return 0;
}