#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 300005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,a[maxn];
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  int i;
  for(i = 1;a[i] == a[n];i++);
  int ans = n - i;
  for(i = n;a[i] == a[1];i--);
  ans = max(ans,i - 1);
  printf("%d\n",ans);
  return 0;
}