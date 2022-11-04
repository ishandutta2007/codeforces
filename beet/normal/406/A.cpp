#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1111][1111];
signed main(){
  int n;
  scanf("%lld",&n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      scanf("%lld",&a[i][j]);
  int ans=0;
  for(int i=0;i<n;i++) ans+=a[i][i];
  int q;
  scanf("%lld",&q);
  int y,z;
  for(int i=0;i<q;i++){
    scanf("%lld",&y);
    if(y==3){
      printf("%lld",ans%2);
      continue;
    }
    scanf("%lld",&z);
    z--;
    ans++;
    a[z][z]=!a[z][z];
  }
  puts("");
  return 0;
}