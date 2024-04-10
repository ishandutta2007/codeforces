#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_V 200050
ll INF = -(1LL<<50LL);
vector<ll> G[MAX_V];
ll a[MAX_V],memo[MAX_V],memo2[MAX_V];
ll dfs(ll x,ll p){
  ll res=a[x];
  for(ll i=0;i<(ll)G[x].size();i++){
    if(G[x][i]==p) continue;
    res+=dfs(G[x][i],x);
    memo2[x]=max(memo2[x],memo2[G[x][i]]);
  }
  memo2[x]=max(memo2[x],res);
  return memo[x]=res;
}
ll dfs2(ll x, ll p){
  ll res=INF;
  priority_queue<ll> q;
  for(ll i=0;i<(ll)G[x].size();i++) {
    if(G[x][i]==p) continue;
    res=max(res,dfs2(G[x][i],x));
    q.push(memo2[G[x][i]]);
  }
  if(q.size()>1){
    ll m1,m2;
    m1=q.top();q.pop();
    m2=q.top();q.pop();
    res=max(res,m1+m2);
  }
  return res;
}
int main(){
  ll n;
  cin>>n;
  for(ll i=0;i<n;i++) cin>>a[i],memo[i]=INF,memo2[i]=INF;
  for(ll i=0;i<n-1;i++){
    ll u,v;
    cin>>u>>v;
    G[u-1].push_back(v-1);
    G[v-1].push_back(u-1);
  }
  dfs(0,-1);
  ll ans=dfs2(0,-1);
  //for(ll i=0;i<n;i++) cout << i << ":" << memo[i] <<"/"<< memo2[i]<<endl;
  if(ans==INF) cout << "Impossible" << endl;
  else cout << ans << endl;
  return 0;
}