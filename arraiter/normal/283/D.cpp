#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int n,dp[5050];ll A[5050];

int main(){
  cin>>n;rep(i,1,n)cin>>A[i];int ans=n-1;
  rep(i,1,n){
    dp[i]=i-1;ll x=A[i];
    per(j,i-1,1){
      if((x%2==1&&A[j]%x==0)||(x%2==0&&A[j]%x==x/2))dp[i]=min(dp[i],dp[j]+i-j-1);
      if(x%2==0)x/=2;
    }
    ans=min(ans,dp[i]+n-i);
  }
  cout<<ans<<endl;
  return 0;
}