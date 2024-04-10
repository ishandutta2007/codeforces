#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int l1[n],r1[n];
  for(int i=0;i<n;i++) cin>>l1[i]>>r1[i];
  int m;
  cin>>m;
  int l2[m],r2[m];
  for(int i=0;i<m;i++) cin>>l2[i]>>r2[i];

  int mal1=l1[0],mir1=r1[0];
  for(int i=0;i<n;i++){
    mal1=max(mal1,l1[i]);
    mir1=min(mir1,r1[i]);
  }
  int mal2=l2[0],mir2=r2[0];
  for(int i=0;i<m;i++){
    mal2=max(mal2,l2[i]);
    mir2=min(mir2,r2[i]);
  }
  int ans=0;
  ans=max(ans,mal1-mir2);
  ans=max(ans,mal2-mir1);
  cout<<ans<<endl;
  return 0;
}