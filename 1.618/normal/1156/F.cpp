#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 5005
#define mod 998244353
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
inline int getint(){
  char c;int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
int n,a[maxn],cnt[maxn];
vector <int> as;
int f[maxn][maxn];
int fct[maxn],inv_fct[maxn];
int modpow(int x,int y){
  int res = 1;
  while(y){
    if(y & 1) res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    a[i] = getint();
    as.push_back(a[i]);
  }
  sort(as.begin(),as.end());
  as.erase(unique(as.begin(),as.end()),as.end());
  for(int i = 1;i <= n;i++){
    cnt[lower_bound(as.begin(),as.end(),a[i]) - as.begin() + 1]++;
  }
  int m = as.size();
  f[1][0] = 1;
  for(int i = 2;i <= m;i++){
    f[i][0] = 1;
    for(int j = 1;j <= i - 1;j++){
      f[i][j] = (f[i - 1][j] + (ll)f[i - 1][j - 1] * cnt[i - 1]) % mod;
    }
  }
  fct[0] = 1;
  for(int i = 1;i <= n;i++) fct[i] = (ll)fct[i - 1] * i % mod;
  inv_fct[n] = modpow(fct[n],mod - 2);
  for(int i = n - 1;i >= 0;i--) inv_fct[i] = (ll)inv_fct[i + 1] * (i + 1) % mod;
  int ans = 0;
  for(int i = 1;i <= m;i++){
    if(cnt[i] == 1) continue;
    for(int j = 0;j <= i - 1;j++){
      ans = (ans + (ll)f[i][j] * cnt[i] % mod * (cnt[i] - 1) % mod * inv_fct[n] % mod * fct[n - j - 2]) % mod;
    }
  }
  printf("%d\n",ans);
  return 0;
}