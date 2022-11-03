#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T> void chmin(T &a,T b){if(a>b) a=b;}
template<typename T> void chmax(T &a,T b){if(a<b) a=b;}

signed main(){
  Int n,l;
  cin>>n>>l;
  vector<Int> c(n);
  for(Int i=0;i<n;i++) cin>>c[i];
  for(Int i=1;i<n;i++)
    chmin(c[i],c[i-1]*2);
  Int ans=1e18,tmp=0;
  for(Int i=n-1;i>=0;i--){
    Int x=1LL<<i;
    Int k=l/x;
    l%=x;
    tmp+=k*c[i];
    chmin(ans,tmp+(l==0?Int(0):c[i]));
  }
  cout<<ans<<endl;
  return 0;
}