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

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<vector<Int> > G(n);
  for(Int i=1;i<n;i++){
    Int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }
  
  vector<Int> dep(n);
  using T = tuple<Int, Int, Int>;
  queue<T> qt;
  for(Int u:G[0])
    qt.emplace(u,0,u),dep[u]=1;
  
  vector<vector<Int> > vs(n);
  while(!qt.empty()){
    Int v,p,r;
    tie(v,p,r)=qt.front();qt.pop();
    Int flg=1;
    for(Int u:G[v]){
      if(u==p) continue;
      dep[u]=dep[v]+1;
      qt.emplace(u,v,r);
      flg=0;
    }
    if(flg) vs[r].emplace_back(dep[v]);
  }
  
  Int ans=0;
  for(Int u:G[0]){
    sort(vs[u].begin(),vs[u].end());
    for(Int i=1;i<(Int)vs[u].size();i++)
      chmax(vs[u][i],vs[u][i-1]+1);
    chmax(ans,vs[u].back());
  }
  cout<<ans<<endl;
  return 0;
}