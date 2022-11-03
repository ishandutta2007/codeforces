#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;


template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,u;
  cin>>n>>u;
  double ans=-1;
  vector<Int> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];

  for(Int i=0;i<n;i++){
    Int j=i+1;
    Int k=--upper_bound(v.begin(),v.end(),v[i]+u)-v.begin();
    if(i<j&&j<k) chmax(ans,double(v[k]-v[j])/double(v[k]-v[i]));
  }

  if(ans<0) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}