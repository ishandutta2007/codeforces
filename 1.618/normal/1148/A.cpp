#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
ll a,b,x,y,z;
int main(){
  x = getint(), y = getint(), z = getint();
  a += x + z;
  b += y + z;
  printf("%I64d\n",min(a,b) * 2 + (!(a == b)));
  return 0;
}