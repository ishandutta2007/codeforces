#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n;
  cin>>n;
  vector<Int> p(n);
  for(Int i=0;i<n;i++) cin>>p[i];
  for(Int i=0;i<n;i++) p[i]--;

  const Int MOD = 1e9+7;
  vector<Int> dp(n+1,0);
  vector<Int> su(n+2,0);
  for(Int i=0;i<n;i++){
    if(i==p[i]) dp[i]=1;
    else{
      dp[i]=su[i]+(MOD-su[p[i]])+(i-p[i])+1;
      dp[i]%=MOD;
    }
    su[i+1]=su[i]+dp[i];
    su[i+1]%=MOD;
    //cout<<i<<" "<<dp[i]<<endl;
  }
  Int ans=n;
  for(Int i=0;i<n;i++) ans+=dp[i];
  ans%=MOD;
  cout<<ans<<endl;
  return 0;
}