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
  vector<Int> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];

  auto no=[]{cout<<"NO"<<endl;exit(0);};
  
  a.erase(unique(a.begin(),a.end()),a.end());
  if((Int)a.size()!=n) no();

  Int x=1e9,y=-1;
  for(Int i=1;i<n;i++)
    if(abs(a[i]-a[i-1])!=1) y=abs(a[i]-a[i-1]);

  if(y<0){
    y=1e9;
    cout<<"YES"<<endl;
    cout<<x<<" "<<y<<endl;
    return 0;
  }
  
  for(Int i=0;i<n-1;i++){
    if(a[i]%y==0&&a[i]+1==a[i+1]) no();
    if(a[i]%y==1&&a[i]-1==a[i+1]) no();
    if(abs(a[i]-a[i+1])!=1&&abs(a[i]-a[i+1])!=y) no();
  }
  
  cout<<"YES"<<endl;
  cout<<x<<" "<<y<<endl;
  return 0;
}