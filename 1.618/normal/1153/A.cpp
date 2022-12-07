#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,t,s,d,val,mini = inf,ans;
int main(){
  n = getint(), t = getint();
  for(int i = 1;i <= n;i++){
    s = getint(), d = getint();
    if(s >= t) val = s;
    else if((t - s) % d == 0) val = s;
    else val = s + (t - s) / d * d + d;
    if(val < mini){
      mini = val;
      ans = i;
    }
  }
  printf("%d\n",ans);
  return 0;
}