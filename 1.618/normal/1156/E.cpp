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
int n,a[maxn],pos[maxn],t[18][maxn],row[maxn];
ll ans;
void rmq_ini(){
  int st = 2;
  for(int i = 1;i <= n;i++){
    if(i == st){
      row[i] = row[i - 1] + 1;
      st <<= 1;
    }else{
      row[i] = row[i - 1];
    }
  }
  for(int i = 1;i <= n;i++) t[0][i] = a[i];
  for(int i = 1;i <= 17;i++){
    for(int j = 1;j + (1 << i) - 1 <= n;j++){
      t[i][j] = max(t[i - 1][j],t[i - 1][j + (1 << (i - 1))]);
    }
  }
}
int rmq(int l,int r){
  int ro = row[r - l];
  return max(t[ro][l],t[ro][r - (1 << ro) + 1]);
}
void solve(int l,int r){
  if(l >= r - 1) return;
  int mid = pos[rmq(l,r)];
  solve(l,mid - 1);
  solve(mid + 1,r);
  int lenl = mid - l, lenr = r - mid;
  if(lenl < lenr){
    for(int i = l;i < mid;i++){
      int p = pos[a[mid] - a[i]];
      if(mid < p && p <= r) ans++;
    }
  }else{
    for(int i = mid + 1;i <= r;i++){
      int p = pos[a[mid] - a[i]];
      if(l <= p && p < mid) ans++;
    }
  }
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    a[i] = getint();
    pos[a[i]] = i;
  }
  rmq_ini();
  solve(1,n);
  printf("%I64d\n",ans);
  return 0;
}