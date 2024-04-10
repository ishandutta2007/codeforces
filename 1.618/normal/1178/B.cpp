#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 1000005
using namespace std;
typedef long long ll;

int n,sum[maxn],suf[maxn];
char s[maxn];
int main(){
  scanf("%s",s + 1);
  n = strlen(s + 1);
  for(int i = 1;i <= n;i++){
    sum[i] = sum[i - 1];
    if(i > 1 && s[i] == 'v' && s[i - 1] == 'v') sum[i]++;
  }
  for(int i = n;i >= 1;i--){
    suf[i] = suf[i + 1];
    if(i < n && s[i] == 'v' && s[i + 1] == 'v') suf[i]++;
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    if(s[i] == 'o') ans += (ll)sum[i - 1] * suf[i + 1];
  }
  printf("%I64d\n",ans);
  return 0;
}