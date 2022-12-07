#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 105
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int a[maxn],b[maxn],c[maxn][maxn],n,m,h;
int res[maxn][maxn];
int main(){
  n = getint(), m = getint(), h = getint();
  for(int i = 1;i <= m;i++) a[i] = getint();
  for(int i = 1;i <= n;i++) b[i] = getint();
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      c[i][j] = getint();
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(!c[i][j]) res[i][j] = 0;
      else res[i][j] = min(b[i],a[j]);
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      printf("%d%c",res[i][j],j == m ? '\n' : ' ');
    }
  }
  return 0;
}