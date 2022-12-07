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
#define maxn 100005
int n,p[maxn],siz[maxn],hei[maxn];
vector <int> son[maxn],blank,ans;
void calc_siz(int u){
  siz[u] = 1;
  for(int i = 0;i < (int)son[u].size();i++){
    int v = son[u][i];
    calc_siz(v);
    siz[u] += siz[v];
    hei[u] = max(hei[u],hei[v] + 1);
  }
}
bool cmp(int x,int y){
  return hei[x] < hei[y];
}
void work(int u){
  blank.push_back(u);
  sort(son[u].begin(),son[u].end(),cmp);
  for(int i = 0;i < (int)son[u].size();i++){
    work(son[u][i]);
  }
}
void print(int l,int r){
  int u = blank[l];
  int st = l + 1;
  for(int i = 0;i < (int)son[u].size();i++){
    int v = son[u][i];
    print(st,st + siz[v] - 1);
    if(i + 1 < (int)son[u].size())
      for(int j = 1;j <= hei[v] + 1;j++) ans.push_back(son[u][i + 1]);
    st += siz[v];
  }
}
int main(){
  n = getint();
  for(int i = 1;i <= n - 1;i++){
    p[i] = getint();
    son[p[i]].push_back(i);
  }
  calc_siz(0);
  work(0);
  print(0,n - 1);
  for(int i = 0;i < n;i++)
    printf("%d%c",blank[i],i == n - 1 ? '\n' : ' ');
  printf("%d\n",(int)ans.size());
  for(int i = 0;i < (int)ans.size();i++)
    printf("%d%c",ans[i],i == (int)ans.size() - 1 ? '\n' : ' ');
  return 0;
}