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
ll n,m,ta,tb,k;
ll a[maxn],b[maxn];
int main(){
  n = getint(), m = getint(), ta = getint(), tb = getint(), k = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  for(int i = 1;i <= m;i++) b[i] = getint();
  if(k >= n){
    puts("-1");
    return 0;
  }
  ll ans = 0;
  for(int i = 1;i <= k + 1;i++){
    int r = k - i + 1;
    int s = lower_bound(b + 1,b + m + 1,a[i] + ta) - b;
    if(m - s + 1 <= r){
      puts("-1");
      return 0;
    }
    ans = max(ans,b[s + r] + tb);
  }
  printf("%I64d\n",ans);
  return 0;
}