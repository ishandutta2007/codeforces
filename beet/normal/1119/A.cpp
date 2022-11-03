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
  vector<Int> c(n);
  for(Int i=0;i<n;i++) cin>>c[i];

  Int ans=0;
  using P = pair<Int, Int>;  
  vector<P> vp;
  for(Int i=0;i<n;i++){
    Int flg=0;
    for(auto p:vp){
      if(p.second==c[i]){
        flg=1;
        continue;
      }
      chmax(ans,i-p.first);
    }
    if(flg==0) vp.emplace_back(i,c[i]);
    
    sort(vp.begin(),vp.end());
    while(vp.size()>5u) vp.pop_back();
  }  

  cout<<ans<<endl;
  return 0;
}