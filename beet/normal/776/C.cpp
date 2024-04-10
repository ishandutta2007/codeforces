#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int INF=1LL<<55LL;
  int n,k;
  cin>>n>>k;
  int m=0;
  int p[60];
  p[0]=1;
  if(k==1){
    m=1;
  }else if(k==-1){
    p[1]=-1;
    m=2;
  }else{
    for(int i=0;abs(p[i])<INF;i++){
      p[i+1]=p[i]*k;
      m=i+1;
    }
  }
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int ans=0,tmp=0;
  map<int,int> ma;
  for(int i=0;i<n;i++){
    ma[tmp]++;
    tmp+=a[i];
    for(int j=0;j<m;j++)
      if(ma.count(tmp-p[j]))
	ans+=ma[tmp-p[j]];
  }
  cout<<ans<<endl;
  return 0;
}