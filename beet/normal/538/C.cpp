#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin>>n>>m;
  int d[m],h[m];
  for(int i=0;i<m;i++) cin>>d[i]>>h[i];
  int ans=h[0]+(d[0]-1);
  for(int i=0;i<m-1;i++){
    int x=(d[i+1]-d[i])-abs(h[i]-h[i+1]);
    if(x<0){
      cout<<"IMPOSSIBLE"<<endl;
      return 0;
    }
    ans=max(ans,max(h[i],h[i+1])+x/2);
  }
  ans=max(ans,h[m-1]+(n-d[m-1]));
  cout<<ans<<endl;
  return 0;
}