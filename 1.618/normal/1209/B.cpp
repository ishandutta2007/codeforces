#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 105
using namespace std;
typedef long long ll;

int n,a[maxn],b[maxn];
char s[maxn];
bool on(int id,int t){
  if(t < b[id]) return s[id] - '0';
  return (s[id] - '0') ^ 1 ^ (((t - b[id]) / a[id]) & 1);
}
int main(){
  scanf("%d",&n);
  scanf("%s",s + 1);
  for(int i = 1;i <= n;i++) scanf("%d%d",&a[i],&b[i]);
  int ans = 0;
  for(int t = 0;t <= 300;t++){
    int res = 0;
    for(int i = 1;i <= n;i++){
      res += on(i,t);
    }
    ans = max(ans,res);
  }
  printf("%d\n",ans);
  return 0;
}