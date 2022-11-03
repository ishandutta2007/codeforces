#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
const Int MAX = 2020;
Int D[MAX][MAX]={};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n;
  cin>>n;
  for(Int i=0;i<n;i++)
    for(Int j=1;j<n-i;j++)
      cin>>D[i][i+j],D[i+j][i]=D[i][i+j];

  const Int INF = 2e9;
  Int mi=INF;
  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      if(i!=j) chmin(mi,D[i][j]);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      if(i!=j) D[i][j]-=mi;

  vector<Int> dp(n,INF);
  for(Int i=0;i<n;i++)
    for(Int j=0;j<n;j++)
      if(i!=j) chmin(dp[i],D[i][j]*2);

  vector<Int> used(n,0);
  for(Int t=0;t<n;t++){
    Int k=-1;
    for(Int i=0;i<n;i++){
      if(used[i]) continue;
      if(k<0 or dp[k]>dp[i]) k=i;
    }
    used[k]=1;
    for(Int i=0;i<n;i++)
      chmin(dp[i],dp[k]+D[k][i]);
  }

  for(Int i=0;i<n;i++) cout<<dp[i]+mi*(n-1)<<newl;
  return 0;
}