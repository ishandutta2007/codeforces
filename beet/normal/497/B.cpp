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
  vector<Int> as(n);
  for(Int i=0;i<n;i++) cin>>as[i],as[i]--;

  vector< vector<Int> > G(2);
  G[0].emplace_back(0);
  G[1].emplace_back(0);
  for(Int i=0;i<n;i++) G[as[i]].emplace_back(i+1);

  using P = pair<Int, Int>;
  vector<P> vp;
  for(Int t=1;t<=n;t++){
    Int i=0,j=0,p=0,q=0;
    while(1){
      //cout<<i<<" "<<j<<endl;
      if(i+t<(Int)G[0].size()){
        if(j+t<(Int)G[1].size()){
          if(G[0][i+t]<G[1][j+t]){
            i=i+t;
            j=--lower_bound(G[1].begin(),G[1].end(),G[0][i])-G[1].begin();
            p++;
          }else{
            j=j+t;
            i=--lower_bound(G[0].begin(),G[0].end(),G[1][j])-G[0].begin();
            q++;
          }
        }else{
          i=i+t;
          p++;
        }
      }else{
        if(j+t<(Int)G[1].size()){
          j=j+t;
          q++;
        }else{
          break;
        }
      }
    }
    if(G[0][i]==n&&p>q) vp.emplace_back(p,t);
    if(G[1][j]==n&&p<q) vp.emplace_back(q,t);
  }

  sort(vp.begin(),vp.end());
  cout<<vp.size()<<endl;
  for(auto p:vp) cout<<p.first<<" "<<p.second<<"\n";
  cout<<flush;
  return 0;
}