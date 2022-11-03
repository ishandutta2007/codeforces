#include <bits/stdc++.h>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using Int = long long;
const char newl = '\n';


template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


vector<Int> bfs(vector<Int> ss,vector< vector<Int> > G){
  Int n=G.size();
  vector<Int> dp(n,-1);
  queue<Int> que;
  for(Int s:ss){
    dp[s]=0;
    que.emplace(s);
  }
  while(!que.empty()){
    Int v=que.front();que.pop();
    for(Int u:G[v]){
      if(~dp[u]) continue;
      dp[u]=dp[v]+1;
      que.emplace(u);
    }
  }
  return dp;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m,k,s;
  cin>>n>>m>>k>>s;

  auto as=read(n);

  vector<vector<Int>> G(n);
  for(Int i=0;i<m;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  for(Int &a:as) a--;

  vector<vector<Int>> D(n);
  for(Int t=0;t<k;t++){
    vector<Int> ss;
    for(Int i=0;i<n;i++)
      if(as[i]==t) ss.emplace_back(i);

    auto ds=bfs(ss,G);
    for(Int i=0;i<n;i++)
      D[i].emplace_back(ds[i]);
  }

  for(Int i=0;i<n;i++){
    if(i) cout<<' ';
    sort(D[i].begin(),D[i].end());
    D[i].resize(s);
    Int sum=0;
    for(Int d:D[i]) sum+=d;
    cout<<sum;
  }
  cout<<newl;
  return 0;
}