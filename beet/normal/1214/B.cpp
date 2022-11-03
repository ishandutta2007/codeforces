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
  Int b,g,n;
  cin>>b>>g>>n;

  Int ans=0;
  for(Int i=0;i<=n;i++){
    Int j=n-i;
    if(i>b||j>g) continue;
    ans++;
  }

  cout<<ans<<endl;
  return 0;
}