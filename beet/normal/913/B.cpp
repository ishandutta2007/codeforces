#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  Int n;
  cin>>n;
  vector<Int> p(n,0);
  for(Int i=1;i<n;i++) cin>>p[i];
  vector<Int> c(n+1,0);
  for(Int i=1;i<n;i++) c[--p[i]]++;
  
  vector<Int> d(n+1,0);
  for(Int i=0;i<n;i++)
    if(!c[i]) d[p[i]]++;
  
  for(Int i=0;i<n;i++){
    if(c[i]&&d[i]<3){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}