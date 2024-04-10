#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;

  vector<vector<Int> > G(n);
  for(Int i=0;i<n;i++){
    Int p;
    cin>>p;
    if(p==0) continue;
    p--;
    G[p].emplace_back(i);
    G[i].emplace_back(p);
  }

  vector<Int> dp(n,0);
  {
    function<void(Int,Int)> dfs=[&](Int v,Int p){
      for(Int u:G[v]){
	if(u==p) continue;
	dfs(u,v);
	dp[v]^=!dp[u];
      }
    };
    dfs(0,-1);
    if(dp[0]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  
  vector<Int> ans;
  function<void(Int,Int)> dfs=[&](Int v,Int p){
    for(Int u:G[v]){
      if(u==p) continue;
      if(dp[u]) dfs(u,v);
    }
    ans.emplace_back(v);    
    for(Int u:G[v]){
      if(u==p) continue;
      if(!dp[u]) dfs(u,v);
    }
  };
  cout<<"YES"<<endl;
  dfs(0,-1);
  for(Int i:ans) cout<<i+1<<endl;
  return 0;
}