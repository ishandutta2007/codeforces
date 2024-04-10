#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 505
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,m;
int a[maxn][maxn],b[maxn][maxn];
void toggle(int x,int y){
  a[x][y] ^= 1;
  a[x + 1][y] ^= 1;
  a[x][y + 1] ^= 1;
  a[x + 1][y + 1] ^= 1;
}
int main(){
  n = getint(), m = getint();
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      a[i][j] = getint();
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      b[i][j] = getint();
    }
  }
  for(int i = 1;i < n;i++){
    for(int j = 1;j < m;j++){
      if(a[i][j] ^ b[i][j]) toggle(i,j);
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      if(a[i][j] ^ b[i][j]){
        puts("No");
        return 0;
      }
    }
  }
  puts("Yes");
  return 0;
}