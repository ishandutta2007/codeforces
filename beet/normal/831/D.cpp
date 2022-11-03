#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,p;
int a[1111],b[2222];
int dp[1111][2222];
int INF=1LL<<55LL;
int dfs(int i,int j){
  if(i==n) return 0;
  if(j==k) return INF;
  if(~dp[i][j]) return dp[i][j];
  int res=INF;
  res=min(res,dfs(i,j+1));
  res=min(res,max(dfs(i+1,j+1),abs(a[i]-b[j])+abs(p-b[j])));
  return dp[i][j]=res;
}
signed main(){
  cin>>n>>k>>p;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<k;i++) cin>>b[i];
  sort(a,a+n);
  sort(b,b+k);
  memset(dp,-1,sizeof(dp));
  cout<<dfs(0,0)<<endl;
  return 0;
}