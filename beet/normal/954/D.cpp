#include<bits/stdc++.h>
using namespace std;
using Int = long long;


//INSERT ABOVE HERE
signed main(){
  Int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  vector<vector<Int> > G(n);
  for(Int i=0;i<m;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  auto bfs=[&](auto &dp,Int v){
    queue<Int> q;
    dp[v]=0;
    q.emplace(v);
    while(!q.empty()){
      v=q.front();q.pop();
      for(Int u:G[v]){
	if(~dp[u]) continue;
	dp[u]=dp[v]+1;
	q.emplace(u);
      }
    }
  };
  
  vector<Int> dps(n,-1),dpt(n,-1);
  bfs(dps,s);
  bfs(dpt,t);

  Int ans=0,len=dps[t];
  for(Int i=0;i<n;i++)
    for(Int j=0;j<i;j++)
      if(dps[i]+1+dpt[j]>=len&&
	 dps[j]+1+dpt[i]>=len) ans++;
  
  cout<<ans-m<<endl;
  
  return 0;
}