#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int m,n;
  scanf("%lld",&m);
  int q[m];
  for(int i=0;i<m;i++) scanf("%lld",q+i);
  scanf("%lld",&n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%lld",a+i);
  //puts("OK");
  sort(q,q+m);
  sort(a,a+n,greater<int>());
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<q[0]&&i<n;j++,i++) ans+=a[i];
    i++;
  }
  printf("%lld\n",ans);
  return 0;
}