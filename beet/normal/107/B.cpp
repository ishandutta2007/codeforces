#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m,h;
  cin>>n>>m>>h;
  h--;
  int s[m];
  for(int i=0;i<m;i++) cin>>s[i];
  int a=0;
  for(int i=0;i<m;i++) a+=s[i];
  if(a<n){
    cout<<-1<<endl;
    return 0;
  }
  if(n-1>a-s[h]){
    cout<<1<<endl;
    return 0;
  }
  double ans=1.0;
  for(int i=0;i<n-1;i++){
    ans*=a-s[h]-i;
    ans/=a-1-i;
  }
  printf("%.12f\n",1.0-ans);
  return 0;
}