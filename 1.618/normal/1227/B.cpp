#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 100005
using namespace std;
typedef long long ll;
int t,n,q[maxn],p[maxn];
void solve(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++) scanf("%d",&q[i]);
  int ed = 0;
  vector <int> buc;
  for(int i = 1;i <= n;i++){
    if(q[i] > q[i - 1]){
      for(int j = ed + 1;j < q[i];j++) buc.push_back(j);
      p[i] = ed = q[i];
    }else{
      if(buc.empty()){
        puts("-1");
        return;
      }
      p[i] = buc.back();
      buc.pop_back();
    }
  }
  for(int i = 1;i <= n;i++) printf("%d%c",p[i],i == n ? '\n' : ' ');
}
int main(){
  scanf("%d",&t);
  while(t--) solve();
  return 0;
}