#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin>>n>>m;
  int x[n],a[m],b[m],c[m];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<m;i++) cin>>a[i]>>b[i]>>c[i];
  double ans=0;
  for(int i=0;i<m;i++){
    a[i]--;b[i]--;
    ans=max(ans,(double)(x[a[i]]+x[b[i]])/c[i]);
  }
  printf("%.12f\n",ans);
  return 0;
}