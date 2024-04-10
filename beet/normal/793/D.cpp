#include<bits/stdc++.h>
using namespace std;
int dp[81][81][81][81];
typedef pair<int,int> P;
vector<P> G[81];
struct st{
  int n,p,l,r;
  st(){}
  st(int n,int p,int l,int r):n(n),p(p),l(l),r(r){}
};
signed main(){
  memset(dp,-1,sizeof(dp));
  int n,k,m;
  cin>>n>>k>>m;
  for(int i=0;i<m;i++){
    int u,v,c;
    cin>>u>>v>>c;
    u--;v--;
    G[u].emplace_back(v,c);
  }
  queue<st> q;
  for(int i=0;i<n;i++){
    q.emplace(1,i,0,i);
    q.emplace(1,i,i+1,n);
    dp[1][i][0][i]=0;
    dp[1][i][i+1][n]=0;
  }
  int ans=-1;
  while(!q.empty()){
    st p=q.front();q.pop();
    if(p.n==k){
      if(ans<0||dp[p.n][p.p][p.l][p.r]<ans)
	ans=dp[p.n][p.p][p.l][p.r];
      continue;
    }
    for(int i=0;i<(int)G[p.p].size();i++){
      int nn=p.n+1,np=G[p.p][i].first,nl=p.l,nr=p.r;
      if(np<nl||nr<=np) continue;
      int nc=dp[p.n][p.p][p.l][p.r]+G[p.p][i].second;
      if(dp[nn][np][nl][np]<0){
	dp[nn][np][nl][np]=nc;
	q.emplace(nn,np,nl,np);
      }
      dp[nn][np][nl][np]=min(dp[nn][np][nl][np],nc);
       if(dp[nn][np][np+1][nr]<0){
	dp[nn][np][np+1][nr]=nc;
	q.emplace(nn,np,np+1,nr);
      }
      dp[nn][np][np+1][nr]=min(dp[nn][np][np+1][nr],nc);
    }
  }
  cout<<ans<<endl;
  return 0;
}