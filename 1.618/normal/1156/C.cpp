#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,z,x[maxn],ans;
bool vis[maxn];
bool check(int a){
  int i = 1, j = n - a + 1;
  for(int k = 0;k < a;k++) if(x[j + k] - x[i + k] < z) return false;
  return true;
}
int main(){
  n = getint(), z = getint();
  for(int i = 1;i <= n;i++) x[i] = getint();
  sort(x + 1,x + n + 1);
  int lb = 0, rb = n >> 1;
  while(lb < rb){
    int mid = (lb + rb + 1) >> 1;
    if(check(mid)) lb = mid;
    else rb = mid - 1;
  }
  printf("%d\n",lb);
  return 0;
}