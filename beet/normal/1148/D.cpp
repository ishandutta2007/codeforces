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
  vector<Int> as(n),bs(n);
  for(Int i=0;i<n;i++) cin>>as[i]>>bs[i];

  using P = pair<Int, Int>;
  vector<P> vp1,vp2;
  for(Int i=0;i<n;i++){
    if(as[i]<bs[i]) vp1.emplace_back(bs[i],i);
    if(as[i]>bs[i]) vp2.emplace_back(bs[i],i);
  }

  sort(vp1.rbegin(),vp1.rend());
  sort(vp2.begin(),vp2.end());

  vector<Int> ans;
  if(vp1.size()>vp2.size()){
    for(auto p:vp1) ans.emplace_back(p.second);
  }else{
    for(auto p:vp2) ans.emplace_back(p.second);
  }
  
  cout<<ans.size()<<endl;
  for(Int i=0;i<(Int)ans.size();i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}