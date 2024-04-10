#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define mp make_pair
#define maxm 2005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
int n,m;
bool checkp(int x){
  if(x == 1) return false;
  for(int i = 2;i * i <= x;i++) if(x % i == 0) return false;
  return true;
}
P el[maxm];
int k;
void print(){
  printf("%d\n",k);
  for(int i = 1;i <= k;i++){
    printf("%d %d\n",el[i].first + 1,el[i].second + 1);
  }
  bufo.flush();
}
vector <int> notadjs;
void make2(){
  int u = notadjs.back(); notadjs.pop_back();
  int v = notadjs.back(); notadjs.pop_back();
  el[++k] = mp(u,v);
}
void make4(){
  int u[4];
  for(int i = 0;i < 4;i++){
    u[i] = notadjs.back();
    notadjs.pop_back();
  }
  for(int i = 0;i < 4;i++){
    for(int j = i + 1;j < 4;j++){
      el[++k] = mp(u[i],u[j]);
    }
  }
}
int main(){
  n = getint();
  for(m = n;m <= (n << 1);m++) if(checkp(m)) break;
  for(int i = 0;i < n;i++){
    el[++k] = mp(i,(i + 1) % n);
  }
  if(n == 3 || n == 5 || n == 7){
    print();
    return 0;
  }
  if(n == 4 || n == 6){
    el[++k] = mp(0,2);
    print();
    return 0;
  }
  if(n & 1){
    for(int i = 0;i < n;i++) notadjs.push_back((i << 1) % n);
  }else{
    for(int i = 0;i < n;i += 2) notadjs.push_back(i);
    for(int i = 1;i < n;i += 2) notadjs.push_back(i);
  }
  int k = (m - n) % 6;
  for(int i = 1;i <= k;i++) make2();
  int mm = (m - n - k) / 6;
  for(int i = 1;i <= mm;i++) make4();
  print();
  return 0;
}