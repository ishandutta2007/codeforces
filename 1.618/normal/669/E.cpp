#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <map>
#define Len 1000000000
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
struct BIT{
  map <int,int> b;
  BIT(){
    b.clear();
  }
  void add(int pos,int x){
    for(int i = pos;i <= Len;i += i & -i) b[i] += x;
  }
  int sum(int pos){
    int res = 0;
    for(int i = pos;i;i -= i & -i) if(b.find(i) != b.end()) res += b[i];
    return res;
  }
};
map <int,BIT> dat;
int n;
int main(){
  n = getint();
  while(n--){
    int tp = getint(), t = getint(), x = getint();
    if(tp == 1){
      dat[x].add(t,1);
    }else if(tp == 2){
      dat[x].add(t,-1);
    }else{
      printf("%d\n",dat[x].sum(t));
    }
  }
  return 0;
}