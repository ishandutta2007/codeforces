#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed dp[2][26][111][111];
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<vector<vector<Int> > > G(n,vector<vector<Int> >(26));
  for(Int i=0;i<m;i++){
    Int u,v;
    char c;
    cin>>u>>v>>c;
    u--;v--;
    G[u][c-'a'].emplace_back(v);
  }
  memset(dp,-1,sizeof(dp));
  function<signed(Int,Int,Int,Int)> dfs=[&](Int t,Int c,Int x,Int y){
    signed &res=dp[t][c][x][y];
    if(~res) return res;
    res=0;
    if(t==0){
      for(Int i=c;i<26;i++)
	for(Int u:G[x][i])
	  res|=!dfs(!t,i,u,y);
    }
    if(t==1){
      for(Int i=c;i<26;i++)
	for(Int u:G[y][i])
	  res|=!dfs(!t,i,x,u);
    }
    //cout<<t<<" "<<c<<" "<<x<<" "<<y<<":"<<res<<endl;
    return res;
  };
  
  for(Int i=0;i<n;i++){
    for(Int j=0;j<n;j++)
      cout<<char('A'+1-dfs(0,0,i,j));
    cout<<endl;
  }
  return 0;
}