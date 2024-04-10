#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 250
signed main(){
  int V;
  cin>>V;
  while(V--){
    double a[MAX];
    for(int i=0;i<MAX;i++) cin>>a[i];
    double exp=0;
    for(int i=0;i<MAX;i++) exp+=a[i];
    exp/=MAX;
    double var=0;
    for(int i=0;i<MAX;i++) var+=(a[i]-exp)*(a[i]-exp);
    var/=MAX;
    double k=exp/var;
    double err=0.60;
    int ans=round(exp);
    if(1.0-err<=k&&k<=1.0+err){
    }else{
      double m=*max_element(a,a+MAX);
      ans=((MAX+1.0)/MAX*m-1.01)/2.0;
    }
    ans=max(ans,10LL);
    ans=min(ans,1000LL);
    cout<<ans<<endl;
  }
  return 0;
}