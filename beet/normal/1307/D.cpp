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


template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

//INSERT ABOVE HERE
signed main(){
  Int n,m,k;
  cin>>n>>m>>k;
  vector<Int> as(k);
  for(Int i=0;i<k;i++) cin>>as[i],as[i]--;

  vector< vector<Int> > G(n);
  for(Int i=0;i<m;i++){
    Int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].emplace_back(y);
    G[y].emplace_back(x);
  }

  auto bfs=
    [&](Int r){
      vector<Int> dp(n,-1);
      queue<Int> que;
      dp[r]=0;
      que.emplace(r);
      while(!que.empty()){
        Int v=que.front();que.pop();
        for(Int u:G[v]){
          if(~dp[u]) continue;
          dp[u]=dp[v]+1;
          que.emplace(u);
        }
      }
      return dp;
    };

  auto d0=bfs(0);
  auto d1=bfs(n-1);
  Int dist=d1[0];

  Int cnt=0;
  for(Int a:as) cnt+=dist<=d0[a];

  if(cnt>=2) drop(dist);

  auto calc=
    [&](Int i,Int j){
      return min({dist,d0[i]+1+d1[j],d0[j]+1+d1[i]});
    };

  Int ans=0;
  if(cnt==1){
    Int idx=-1;
    for(Int i=0;i<k;i++)
      if(dist<=d0[as[i]])
        idx=i;
    assert(~idx);

    for(Int i=0;i<k;i++){
      if(idx==i) continue;
      chmax(ans,calc(as[i],as[idx]));
    }
  }

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int a:as)
    if(d0[a]<=dist)
      vp.emplace_back(d0[a],a);

  sort(vp.begin(),vp.end());
  for(Int i=0;i+1<(Int)vp.size();i++)
    chmax(ans,calc(vp[i].second,vp[i+1].second));

  cout<<ans<<endl;
  return 0;
}