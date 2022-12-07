#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int BASE = 1000000000;
int q;
ll a,b,m;
ll r[55],x[55];
bool check(int k){//k >= 3
  ll a1 = a / BASE, a2 = a % BASE;
  ll d = 1ll << (k - 2);
  ll x1 = d / BASE, x2 = d % BASE;
  if(a1 * x1 > 0) return false;
  if(a1 * x2 + a2 * x1 >= BASE) return false;
  ll c = b - a * d;
  if(c < 0) return false;
  for(int i = k - 3;i >= 1;i--){
    r[k - i - 1] = 1;
    c -= 1ll << i;
  }
  r[k - 1] = r[k] = 1;
  c -= 2;
  if(c < 0) return false;
  for(int i = k - 3;i >= 1;i--){
    ll r0 = min(c >> i,m - 1);
    c -= r0 << i;
    r[k - i - 1] += r0;
  }
  if(c >= m){
    r[k - 1] += m - 1;
    r[k] += c - (m - 1);
    if(r[k] > m) return false;
  }else{
    r[k] += c;
  }
  return true;
}
void solve(){
  memset(x,0,sizeof(x));
  if(a == b){
    printf("1 %I64d\n",a);
    return;
  }
  if(b - a <= m){
    printf("2 %I64d %I64d\n",a,b);
    return;
  }
  for(int i = 3;i <= 50;i++){
    if(check(i)){
      x[1] = a;
      ll sum = a;
      for(int j = 2;j <= i;j++){
        x[j] = sum + r[j];
        sum += x[j];
      }
      printf("%d ",i);
      for(int j = 1;j <= i;j++){
        printf("%I64d%c",x[j],j == i ? '\n' : ' ');
      }
      return;
    }
  }
  puts("-1");
}
int main(){
  scanf("%d",&q);
  while(q--){
    scanf("%I64d%I64d%I64d",&a,&b,&m);
    solve();
  }
  return 0;
}
// 99999999999998 100000000000000 1