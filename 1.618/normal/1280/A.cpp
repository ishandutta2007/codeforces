#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxx 1000005

using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int t,x,k;
char s[maxx];
void solve(){
  ll len = k;
  bool full = (k >= x);
  for(int i = 1;i <= x;i++){
    int num = s[i] - '1';
    if(!full){
      int tmp = k;
      for(int j = 1;j <= num;j++){
        for(int l = i + 1;l <= tmp;l++){
          s[++k] = s[l];
          if(k == x){
            full = true;
            break;
          }
        }
        if(full) break;
      }
    }
    len = (len + (len - i) * num) % mod;
  }
  printf("%lld\n",(len + mod) % mod);
}
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d",&x);
    scanf("%s",s + 1);
    k = strlen(s + 1);
    solve();
  }
  return 0;
}