#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int x=a[0];
  for(int i=0;i<n;i++) x=__gcd(x,a[i]);
  if(x!=1){
    cout<<-1<<endl;
    return 0;
  }
  int ones=count(a.begin(),a.end(),1);
  if(ones){
    cout<<n-ones<<endl;
    return 0;
  }
  int cnt=n;
  for(int i=0;i<n;i++){
    int g=a[i],j=i;
    while(j<n&&g!=1)
      g=__gcd(g,a[j++]);
    if(g==1) cnt=min(cnt,j-i-1);
  }
  cout<<cnt+(n-1)<<endl;
  return 0;
}