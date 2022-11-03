#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 22;
Int as[MAX][MAX];

signed main(){
  Int n,m;
  cin>>n>>m;
  vector<string> ss(n);
  for(Int i=0;i<n;i++) cin>>ss[i];

  for(Int i=0;i<n;i++)
    for(Int j=0;j<m;j++)
      cin>>as[i][j];

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int j=0;j<m;j++){
    vector<Int> used(n,0);
    for(Int i=0;i<n;i++){
      vp.emplace_back(1<<i,as[i][j]);
      if(used[i]) continue;

      vector<Int> vs;
      for(Int k=0;k<n;k++)
        if(ss[i][j]==ss[k][j])
          vs.emplace_back(k);

      Int bit=0,sum=0,res=as[i][j];
      for(Int v:vs){
        bit|=1<<v;
        sum+=as[v][j];
        chmax(res,as[v][j]);
        used[v]=1;
      }
      //cout<<bit<<" "<<sum<<" "<<res<<endl;
      vp.emplace_back(bit,sum-res);
    }
  }

  map<Int, Int> mp;
  for(auto p:vp) mp[p.first]=p.second;
  for(auto p:vp) chmin(mp[p.first],p.second);
  vp.clear();
  for(auto p:mp) vp.emplace_back(p);

  const Int INF = 1e15;
  Int s=1<<n;
  vector<Int> dp(s,INF);
  dp[0]=0;
  for(auto p:vp)
    for(Int b=0;b<s;b++)
      chmin(dp[b|p.first],dp[b]+p.second);

  cout<<dp[s-1]<<endl;
  return 0;
}