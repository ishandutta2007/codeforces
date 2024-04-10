#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
  int n,x,i,j,k,ans=0;
  cin>>n>>x;
  map<int,int> m;
  int a[n];
  for(i=0;i<n;i++) cin>>a[i],m[a[i]]++;
  if(x) for(i=0;i<n;i++) ans+=((m.find(x^a[i])!=m.end())?m[x^a[i]]:0);
  else for(auto it=m.begin();it!=m.end();++it) ans+=(it->second-1)*(it->second);
  cout << ans/2 << endl;
  return 0;
}