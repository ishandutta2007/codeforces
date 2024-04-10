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
#define maxn 1000005
typedef unsigned long long ull;
const ull mod = 1998585857;
vector < vector <ull> > f1,rf1,f2,rf2;
int n,m;
string s[maxn];
int main(){
  ios::sync_with_stdio(false);
//  freopen("D.in","r",stdin);
  cin >> n >> m;
  f1.resize(n + 2), f2.resize(n + 2);
  rf1.resize(n + 2), rf2.resize(n + 2);
  for(int i = 0;i <= n + 1;i++){
    f1[i].resize(m + 2), f2[i].resize(m + 2);
    rf1[i].resize(m + 2), rf2[i].resize(m + 2);
  }
  for(int i = 1;i <= n;i++) cin >> s[i];
  f1[1][1] = f2[1][1] = 1;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(i == 1 && j == 1) continue;
      if(s[i][j - 1] == '.'){
        f1[i][j] = (f1[i - 1][j] + f1[i][j - 1]) % mod;
        f2[i][j] = f2[i - 1][j] + f2[i][j - 1];
      }
    }
  }
  rf1[n][m] = rf2[n][m] = 1;
  for(int i = n;i >= 1;i--){
    for(int j = m;j >= 1;j--){
      if(i == n && j == m) continue;
      if(s[i][j - 1] == '.'){
        rf1[i][j] = (rf1[i + 1][j] + rf1[i][j + 1]) % mod;
        rf2[i][j] = rf2[i + 1][j] + rf2[i][j + 1];
      }
    }
  }
  if(!f1[n][m] && !f2[n][m]) cout << "0" << endl;
  else{
    for(int i = 1;i <= n;i++){
      for(int j = 1;j <= m;j++){
        if(i == 1 && j == 1) continue;
        if(i == n && j == m) continue;
        if(s[i][j - 1] == '#') continue;
        if(f1[i][j] * rf1[i][j] % mod == f1[n][m] && f2[i][j] * rf2[i][j] == f2[n][m]){
          cout << "1" << endl;
          return 0;
        }
      }
    }
    cout << "2" << endl;
  }
  return 0;
}