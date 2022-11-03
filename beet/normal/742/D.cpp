#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
  ll n,m,W,i,j,k;cin>>n>>m>>W;
  ll w[n],b[n];
  for(i=0;i<n;i++) cin>>w[i];
  for(i=0;i<n;i++) cin>>b[i];
  vector<ll> G[n];
  for(i=0;i<m;i++){
    cin>>j>>k;
    j--;k--;
    G[j].push_back(k);
    G[k].push_back(j);
  }
  bool u[n];
  memset(u,0,sizeof(u));
  vector<P> v;
  vector<vector<ll> > vl;
  for(i=0;i<n;i++){
    if(u[i]) continue;
    queue<ll> q;
    vector<ll> l;
    q.push(i);
    P p=P(0,0);
    while(!q.empty()){
      k=q.front();q.pop();
      if(u[k]) continue;
      u[k]=1;l.push_back(k);
      p.first+=b[k];
      p.second+=w[k];
      for(j=0;j<G[k].size();j++) q.push(G[k][j]);
    }
    v.push_back(p);
    vl.push_back(l);
  }
  ll V=v.size(),ans=0;
  ll dp[V+1][W+1];
  memset(dp,0,sizeof(dp));
  for(i=0;i<V;i++){
    for(j=0;j<W;j++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      for(k=0;k<vl[i].size();k++){
	if(j+w[vl[i][k]]>W) continue;
	dp[i+1][j+w[vl[i][k]]]=max(dp[i+1][j+w[vl[i][k]]],dp[i][j]+b[vl[i][k]]);
      }
      if(j+v[i].second>W) continue;
      dp[i+1][j+v[i].second]=max(dp[i+1][j+v[i].second],dp[i][j]+v[i].first);
    }
  }
  for(i=0;i<=V;i++) for(j=0;j<=W;j++) ans=max(ans,dp[i][j]);
  cout << ans << endl;
  return 0;
}