#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,a[maxn],h,b[maxn];
bool check(int x){
  for(int i = 1;i <= x;i++) b[i] = a[i];
  sort(b + 1,b + x + 1,greater<int>());
  ll res = 0;
  for(int i = 1;i <= x;i += 2) res += b[i];
  return res <= (ll)h;
}
int main(){
  n = getint(), h = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  int lb = 1, rb = n;
  while(lb < rb){
    int mid = (lb + rb + 1) >> 1;
    if(check(mid)) lb = mid;
    else rb = mid - 1;
  }
  printf("%d\n",lb);
  return 0;
}