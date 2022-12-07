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
int cnt[35];
int n;
char s[25];
int calc(int x){
  return x * (x - 1) / 2;
}
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%s",s);
    cnt[s[0] - 'a']++;
  }
  int ans = 0;
  for(int i = 0;i < 26;i++){
    ans += calc(cnt[i] / 2) + calc(cnt[i] - cnt[i] / 2);
  }
  printf("%d\n",ans);
  return 0;
}