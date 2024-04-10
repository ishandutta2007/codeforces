#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  string s;
  cin>>n>>s;
  Int ans=n;
  for(Int l=1;l*2<=n;l++){
    Int flg=1;
    for(Int i=0;i<l;i++)
      flg&=s[i]==s[l+i];
    if(!flg) continue;
    chmin(ans,n-l+1);
  }
  cout<<ans<<endl;
  return 0;
}