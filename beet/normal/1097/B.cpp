#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  
  auto YES=[](){cout<<"YES"<<endl;exit(0);};
  Int s=1<<n;
  for(Int b=0;b<s;b++){
    Int res=0;
    for(Int i=0;i<n;i++){
      if((b>>i)&1) res+=a[i];
      else res+=360-a[i];
    }
    res%=360;
    if(res==0) YES();
  }
  
  cout<<"NO"<<endl;
  return 0;
}