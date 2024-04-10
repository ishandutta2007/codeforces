#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxm 55
#define maxn 10005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,m;
bool dora[maxm][maxn];
int main(){
  m = getint(), n = getint();
  for(int i = 1;i <= m;i++){
    int s = getint();
    for(int j = 1;j <= s;j++){
      int x = getint();
      dora[i][x] = true;
    }
  }
  for(int i = 1;i <= m;i++){
    for(int j = 1;j <= m;j++){
      if(i == j) continue;
      bool app = false;
      for(int k = 1;k <= n;k++){
        if(dora[j][k] && dora[i][k]) app = true;
      }
      if(!app){
        puts("impossible");
        return 0;
      }
    }
  }
  puts("possible");
  return 0;
}