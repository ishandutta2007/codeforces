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
  vector<Int> bs(n);
  for(Int i=0;i<n;i++) cin>>bs[i];

  map<Int, Int> sum;
  for(Int i=0;i<n;i++)
    sum[bs[i]-i]+=bs[i];

  Int ans=0;
  for(auto p:sum)
    chmax(ans,p.second);

  cout<<ans<<endl;
  return 0;
}