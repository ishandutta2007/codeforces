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
  Int n,d,e;
  cin>>n>>d>>e;

  Int ans=n%d;
  for(Int i=0;i*e<=n;i+=5)
    chmin(ans,(n-i*e)%d);

  cout<<ans<<endl;
  return 0;
}