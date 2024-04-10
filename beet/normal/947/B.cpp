#include<bits/stdc++.h>
using namespace std;
using Int = long long;

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
  vector<Int> v(n),t(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  for(Int i=0;i<n;i++) cin>>t[i];
  vector<Int> s(n+1,0);
  for(Int i=0;i<n;i++) s[i+1]=s[i]+t[i];
  vector<Int> x(n+1,0),y(n+1,0);
  for(Int i=0;i<n;i++){
    Int l=i,r=n+1;
    while(l+1<r){
      Int m=(l+r)>>1;
      if((s[m]-s[i])<=v[i]) l=m;
      else r=m;
    }
    //cout<<i<<" "<<l<<" "<<r<<":"<<v[i]<<" "<<(s[l]-s[i])<<endl;
    x[i]++;
    x[l]--;
    y[l]+=v[i]-(s[l]-s[i]);
  }
  
  partial_sum(x.begin(),x.end(),x.begin());
  for(Int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<x[i]*t[i]+y[i];
  }
  cout<<endl;
  return 0;
}