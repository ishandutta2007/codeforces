#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int ans=n*4;
  for(int i=1;i<=n;i++){
    int a=i,b=(n+i-1)/i;
    ans=min(ans,(a+b)*2);
  }
  cout<<ans<<endl;
  return 0;
}