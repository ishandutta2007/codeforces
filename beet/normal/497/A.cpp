#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<string> vs(n);
  for(Int i=0;i<n;i++) cin>>vs[i];
  Int ans=0;
  vector<Int> ok(n,0);
  for(Int j=0;j<m;j++){
    Int ng=0;
    for(Int i=0;i+1<n;i++){
      if(ok[i]) continue;
      ng|=(vs[i][j]>vs[i+1][j]);
    }
    if(ng){
      ans++;
      continue;
    }
    for(Int i=0;i+1<n;i++){
      ok[i]|=(vs[i][j]<vs[i+1][j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}