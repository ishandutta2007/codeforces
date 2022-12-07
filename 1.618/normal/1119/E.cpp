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
ll rest1,rest2,ans;
int main(){
  n = getint();
  for(int i = 0;i < n;i++){
    a[i] = getint();
    ll num = (a[i] >> 1);
    rest2 += (a[i] & 1);
    if(num >= rest2){
      ans += rest2;
      rest1 += num - rest2;
      rest2 = 0;
    }else{
      ans += num;
      rest2 -= num;
    }
  }
  printf("%I64d\n",ans + rest1 * 2 / 3);
  return 0;
}