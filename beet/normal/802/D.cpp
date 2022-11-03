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
    //cout<<exp<<" "<<var<<endl;
    double err=0.70;
    if(1.0-err<=k&&k<=1.0+err) cout<<"poisson"<<endl;
    else cout<<"uniform"<<endl;
  }
  return 0;
}