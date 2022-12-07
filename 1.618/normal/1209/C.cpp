#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
int t,n;
char d[maxn];
vector <int> pos[15];
int ans[maxn];
void solve(){
  memset(ans,0,sizeof(ans));
  scanf("%d",&n);
  scanf("%s",d + 1);
  for(int i = 0;i < 10;i++) pos[i].clear();
  for(int i = 1;i <= n;i++) pos[d[i] - '0'].push_back(d[i] - '0');
  vector <int> res;
  for(int i = 0;i < 10;i++){
    for(int j = 0;j < (int)pos[i].size();j++){
      res.push_back(pos[i][j]);
    }
  }
  int k,j = 1;
  for(k = 0;k < n;k++){
    while(j <= n && d[j] - '0' != res[k]) j++;
    if(j > n) break;
    ans[j++] = 1;
  }
  vector <int> rst;
  for(int i = 1;i <= n;i++) if(ans[i] == 0) rst.push_back(d[i] - '0');
  for(int i = k;i < n;i++){
    if(res[i] != rst[i - k]){
      puts("-");
      return;
    }
  }
  for(int i = 1;i <= n;i++){
    printf("%d",ans[i] ? 1 : 2);
  }
  puts("");
}
int main(){
  scanf("%d",&t);
  while(t--) solve();
  return 0;
}