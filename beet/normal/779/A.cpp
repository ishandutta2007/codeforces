#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  int c[2][5]={};
  for(int i=0;i<n;i++) c[0][a[i]-1]++;
  for(int i=0;i<n;i++) c[1][b[i]-1]++;
  int ans=0;
  for(int i=0;i<5;i++){
    if((c[0][i]+c[1][i])%2){
      cout<<-1<<endl;
      return 0;
    }
    ans+=abs(c[0][i]-(c[0][i]+c[1][i])/2);
  }
  cout<<ans/2<<endl;
  return 0;
}