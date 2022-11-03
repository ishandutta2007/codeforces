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



template<typename T>
struct DiameterForEdge{
  using Edge = pair<Int, T>;
  vector<T> dp;
  vector< vector<Edge> > G;
  DiameterForEdge(Int n):dp(n),G(n){}
  void add_edge(Int u,Int v,T c){
    G[u].emplace_back(v,c);
    G[v].emplace_back(u,c);
  }
  void dfs(Int v,Int p,Int &s){
    if(p<0) dp[v]=T(0);
    if(dp[s]<dp[v]) s=v;
    for(Edge e:G[v]){
      Int u=e.first;
      if(u==p) continue;
      dp[u]=dp[v]+e.second;
      dfs(u,v,s);
    }
  }
  pair<Int, Int> endPoints(){
    Int s=0;
    dfs(s,-1,s);
    Int t=s;
    dfs(t,-1,t);
    return make_pair(s,t);
  }
  T build(){
    Int t=endPoints().second;
    return dp[t];
  }
  vector<T> distance(Int v){
    dfs(v,-1,v);
    return dp;
  }
  vector<T> farthest(){
    Int t=endPoints().second;
    auto ds=dp;
    auto dt=distance(t);
    for(Int i=0;i<(Int)ds.size();i++)
      if(ds[i]<dt[i]) ds[i]=dt[i];
    return ds;
  }
};


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n,k;
  cin>>n>>k;
  DiameterForEdge<Int> G(n);
  for(Int i=1;i<n;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G.add_edge(u,v,1);
  }

  Int S,T;
  tie(S,T)=G.endPoints();
  auto ds=G.distance(S);
  auto dt=G.distance(T);

  if(ds[T]+1<k){
    cout<<"Yes"<<endl;
    for(Int i=0;i<n;i++){
      if(i) cout<<" ";
      cout<<1;
    }
    cout<<endl;
    return 0;
  }

  if(k==2){
    cout<<"Yes"<<endl;
    for(Int i=0;i<n;i++){
      if(i) cout<<" ";
      cout<<((ds[i]&1)?1:2);
    }
    cout<<endl;
    return 0;
  }

  assert(k>=3);

  for(Int i=0;i<n;i++)
    if(ds[i]+dt[i]!=ds[T]&&ds[i]+1>=k&&dt[i]+1>=k) drop("No");

  vector<Int> ans(n);
  for(Int i=0;i<n;i++){
    if(ds[i]+dt[i]==ds[T]){
      ans[i]=ds[i]%k;
      continue;
    }
    if(ds[i]==dt[i]){
      ans[i]=ds[i]%k;
      continue;
    }
    if(ds[i]>dt[i]){
      ans[i]=ds[i]%k;
      continue;
    }
    if(ds[i]<dt[i]){
      Int len=(ds[i]+dt[i]-ds[T]);
      //assert(len<=ds[i]);
      ans[i]=(ds[i]-len)%k;
      continue;
    }
    //assert(0);
  }

  cout<<"Yes"<<endl;
  for(Int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}