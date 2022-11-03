#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


template<typename T> 
map<T, Int> factorize(T x){
  map<T, Int> res;
  for(Int i=2;i*i<=x;i++){
    while(x%i==0){
      x/=i;
      res[i]++;
    }
  }
  if(x!=1) res[x]++;
  return res;
}

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  Int ans=0;
  for(Int x=1;x<=n;x++){
    auto d=factorize(x);
    ans+=d.size()==2u;
  }
  cout<<ans<<endl;
  return 0;
}