#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int x=*min_element(a,a+n);
  bool f=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if((a[i]-x)%k){
      f=1;
      break;
    }
    ans+=(a[i]-x)/k;
  }
  if(f) cout<<-1<<endl;
  else cout<<ans<<endl;
  return 0;
}