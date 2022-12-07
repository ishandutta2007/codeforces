#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <cassert>

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
#define maxm 1000005
#define maxn 505
const int mod = 998244353;
int n,m,t[21][maxm];
int bound[maxm];// 0 for illegal
vector <int> pos[maxn];
int f[maxn << 1][maxn << 1];
inline int qmin(int l,int r){
  if(l == r) return t[0][l];
  int ro = 31 - __builtin_clz(r - l);
  return min(t[ro][l],t[ro][r - (1 << ro) + 1]);
}
int calc(int l,int r){
  assert(l <= r + 1);
  if(l > r) return 1;
  if(!bound[l] || !bound[r]) return 0;
  if(~f[bound[l]][bound[r]]) return f[bound[l]][bound[r]];
  int minc = qmin(l,r), p = pos[minc].front(), q = pos[minc].back();
  if(p < l || q > r) return f[bound[l]][bound[r]] = 0;
  int mid = 1, lcnt = 0, rcnt = 0;
  int i = q;
  while(true){
    rcnt = (rcnt + (ll)calc(q + 1,i) * calc(i + 1,r)) % mod;
    i++;
    if(i > r) break;
    if(pos[t[0][i]].front() < i) return f[bound[l]][bound[r]] = 0;
    i = pos[t[0][i]].back();
  }
  i = p;
  while(true){
    lcnt = (lcnt + (ll)calc(l,i - 1) * calc(i,p - 1)) % mod;
    i--;
    if(i < l) break;
    if(pos[t[0][i]].back() > i) return f[bound[l]][bound[r]] = 0;
    i = pos[t[0][i]].front();
  }
  for(i = 0;i < (int)pos[minc].size() - 1;i++){
    mid = (ll)mid * calc(pos[minc][i] + 1,pos[minc][i + 1] - 1) % mod;
  }
  return f[bound[l]][bound[r]] = (ll)lcnt * rcnt % mod * mid % mod;
}
int main(){
  memset(f,-1,sizeof(f));
  n = getint(), m = getint();
  for(int i = 1;i <= m;i++){
    t[0][i] = getint();
    pos[t[0][i]].push_back(i);
  }
  for(int i = 1;i <= n;i++)
    bound[pos[i].front()] = bound[pos[i].back()] = 1;
  int k = 0;
  for(int i = 1;i <= m;i++)
    if(bound[i]) bound[i] = ++k;
  for(int i = 1;i <= 19;i++){
    for(int j = 1;j + (1 << i) - 1 <= m;j++){
      t[i][j] = min(t[i - 1][j],t[i - 1][j + (1 << (i - 1))]);
    }
  }
  putint(calc(1,m),'\n');
  bufo.flush();
  return 0;
}