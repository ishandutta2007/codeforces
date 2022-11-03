#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n;
  cin>>n;
  vector<Int> v(n);
  for(Int i=0;i<n;i++) cin>>v[i];
  Int ans=0;
  for(Int i=0;i<n;i++){
    Int j=i;
    while(j<n&&v[i]==v[j]) j++;
    ans+=(j-i)*(j-i+1)/2;
    i=j-1;
  }
  cout<<ans<<endl;
  return 0;
}