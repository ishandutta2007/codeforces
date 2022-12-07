#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 1035
using namespace std;
typedef long long ll;
int n, k;
char ans[5];
bool coffee(int x){
  printf("? %d\n", x);
  fflush(stdout);
  scanf("%s", ans);
  if(ans[0] == 'E') exit(0);
  return ans[0] == 'Y';
}
void reset(){
  printf("R\n");
  fflush(stdout);
}
void guess(int d){
  printf("! %d\n", d);
  fflush(stdout);
}
bool fir[maxn];
void solve1(){
  for(int i = 1;i <= n;i++){
    fir[i] = true;
    for(int j = 1;j < i;j++){
      coffee(j);
      if(coffee(i)) fir[i] = false;
    }
  }
}
int belong[maxn], l[maxn], r[maxn];
void solve2(){
  int siz = k / 2, b = n / k;
  for(int i = 1;i <= b * 2;i++){
    l[i] = (i - 1) * siz + 1, r[i] = i * siz;
    for(int j = l[i];j <= r[i];j++) belong[j] = i;
  }
  for(int i = 1;i <= n;i++) fir[i] = true;
  for(int i = 1;i <= b;i++){
    for(int s = 1;s <= i;s++){
      reset();
      for(int t = s;t <= b * 2;t += i){
        for(int j = l[t];j <= r[t];j++){
          if(coffee(j)) fir[j] = false;
        }
      }
    }
  }
  for(int i = 1;i < b;i++){
    for(int j = i + b + 1;j <= b * 2;j++){
      reset();
      for(int m = l[i];m <= r[i];m++) coffee(m);
      for(int m = l[j];m <= r[j];m++) if(coffee(m)) fir[m] = false;
    }
  }
}
int main(){
  scanf("%d%d", &n, &k);
  if(k == 1) solve1();
  else solve2();
  int d = 0;
  for(int i = 1;i <= n;i++) d += fir[i];
  guess(d);
  return 0;
}