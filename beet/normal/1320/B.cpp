#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;


vector<int> bfs(int s,vector< vector<int> > G){
  int n=G.size();
  vector<int> dp(n,-1);
  queue<int> que;
  dp[s]=0;
  que.emplace(s);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      if(~dp[u]) continue;
      dp[u]=dp[v]+1;
      que.emplace(u);
    }
  }
  return dp;
}

//INSERT ABOVE HERE
signed main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> G(n),R(n);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  int k;
  cin>>k;
  vector<int> ps(k);
  for(int i=0;i<k;i++) cin>>ps[i],ps[i]--;

  auto dt=bfs(ps.back(),R);

  int x=0,y=0;
  for(int i=0;i+1<k;i++){
    if(dt[ps[i]]!=dt[ps[i+1]]+1){
      x++;
      y++;
      continue;
    }
    int cnt=0;
    for(int j:G[ps[i]])
      if(dt[j]+1==dt[ps[i]]) cnt++;
    if(cnt>=2) y++;
  }

  cout<<x<<" "<<y<<endl;
  return 0;
}