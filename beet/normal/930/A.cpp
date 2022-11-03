#include<bits/stdc++.h>
using namespace std;
using Int = signed;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> p(n);
  for(Int i=1;i<n;i++) cin>>p[i];
  vector<vector<Int> > G(n);
  for(Int i=1;i<n;i++)
    G[--p[i]].emplace_back(i);

  vector<deque<Int> > dp(n); 
  auto calc=[&](Int v){
    Int idx=-1;
    for(Int u:G[v])
      if(idx<0||dp[idx].size()<dp[u].size()) idx=u;
    if(~idx){
      swap(dp[v],dp[idx]);
      for(Int u:G[v]){
	if(u==idx) continue;
	for(Int i=0;i<(Int)dp[u].size();i++)
	  dp[v][i]^=dp[u][i];
      }
    }
    dp[v].push_front(1);
  };
  for(Int i=n-1;i>=0;i--) calc(i);
  cout<<accumulate(dp[0].begin(),dp[0].end(),0)<<endl;
  return 0;
}