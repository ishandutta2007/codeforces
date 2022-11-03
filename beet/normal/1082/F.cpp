#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 505;
vector<Int> G[MAX];
Int dep[MAX],cnt[MAX];
Int dfs1(Int v,Int d){
  dep[v]=d;
  //for(Int u:G[v]) cout<<v<<"->"<<u<<endl;
  for(Int u:G[v]) cnt[v]+=dfs1(u,d+1);
  //cout<<v<<":"<<cnt[v]<<endl;
  return cnt[v];
}
Int dp[12][MAX][MAX];
Int dfs2(Int k,Int l,Int v){
  Int &res=dp[k][l][v];
  if(~res) return res;
  res=0;
  // use
  if(v!=0&&k>0){
    vector<Int> dp1(k+1,0);
    for(Int u:G[v]){
      vector<Int> nx(k,0);
      for(Int i=0;i<=k-1;i++){
        Int tmp=dfs2(i,v,u);
        for(Int j=0;j<=k;j++)
          if(i+j<=k-1) chmax(nx[i+j],tmp+dp1[j]);
      }
      swap(dp1,nx);
    }
    //cout<<v<<":"<<(dep[v]-dep[l])<<" "<<cnt[v]<<endl;
    chmax(res,*max_element(dp1.begin(),dp1.end())+(dep[v]-dep[l])*cnt[v]);
  }
  // not use
  {
    vector<Int> dp2(k+1,0);
    for(Int u:G[v]){
      vector<Int> nx(k+1,0);
      for(Int i=0;i<=k;i++){
        Int tmp=dfs2(i,l,u);
        for(Int j=0;j<=k;j++)
          if(i+j<=k) chmax(nx[i+j],tmp+dp2[j]);
      }
      swap(dp2,nx);
    }
    chmax(res,*max_element(dp2.begin(),dp2.end()));
  }
  //cout<<k<<" "<<l<<" "<<v<<":"<<res<<endl;
  return res;
}
signed main(){
  Int n,k;
  cin>>n>>k;
  vector<string> ss(n);
  vector<Int> ms(n);
  for(Int i=0;i<n;i++) cin>>ss[i]>>ms[i];

  using P = pair<Int, Int>;
  map<P, Int> nxt;
  Int sz=1,sum=0;
  memset(cnt,0,sizeof(cnt));
  for(Int j=0;j<n;j++){
    string s=ss[j];
    Int pos=0;
    for(Int i=0;i<(Int)s.size();i++){
      P e(pos,s[i]);
      if(!nxt.count(e)){
        nxt[e]=sz++;
        G[pos].emplace_back(nxt[e]);
      }
      pos=nxt[e];
    }
    sum+=s.size()*ms[j];
    cnt[pos]+=ms[j];
  }
  dfs1(0,0);
  
  memset(dp,-1,sizeof(dp));
  cout<<sum-dfs2(k,0,0)<<endl;
  return 0;
}