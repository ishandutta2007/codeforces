#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  int ans=a[1]-a[0],cnt=1;
  for(int i=2;i<n;i++){
    if(ans>a[i]-a[i-1]){
      ans=a[i]-a[i-1];
      cnt=0;
    }
    if(ans==a[i]-a[i-1]) cnt++;
  }
  cout<<ans<<" "<<cnt<<endl;
  return 0;
}