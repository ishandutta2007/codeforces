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
int n,a[maxn],ans;
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  for(int i = 2;i <= n;i++){
    if(a[i] == 1){
      if(a[i - 1] == 1){
        puts("Infinite");
        return 0;
      }
      if(a[i - 1] == 2) ans += 3;
      else ans += 4;
    }
    if(a[i] == 2){
      if(a[i - 1] != 1){
        puts("Infinite");
        return 0;
      }
      ans += 3;
    }
    if(a[i] == 3){
      if(a[i - 1] != 1){
        puts("Infinite");
        return 0;
      }
      ans += 4;
    }
  }
  for(int i = 3;i <= n;i++) if(a[i] == 2 && a[i - 2] == 3) ans--;
  puts("Finite");
  printf("%d\n",ans);
  return 0;
}