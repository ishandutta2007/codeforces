#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n,m;
  cin>>n>>m;
  int g[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>g[i][j];

  int ans=-1;
  int a[n],b[m];
  int c[n],d[m];
  for(int k=0;k<=500;k++){
    memset(a,-1,sizeof(a));
    memset(b,0,sizeof(b));
    a[0]=k;
    bool f=1;
    for(int j=0;j<m;j++){
      f&=a[0]<=g[0][j];
      b[j]=g[0][j]-a[0];
    }
    if(!f) continue; 
    //cout<<k<<":";for(int j=0;j<m;j++) cout<<b[j]<<" ";cout<<endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	f&=b[j]<=g[i][j];
	if(!f) break;
	if(a[i]<0) a[i]=g[i][j]-b[j];
	else f&=a[i]==g[i][j]-b[j];
      }
      if(!f) break;
    }
    if(!f) continue;
    int tmp=0;
    for(int i=0;i<n;i++) tmp+=a[i];
    for(int i=0;i<m;i++) tmp+=b[i];
    if(ans<0||tmp<ans){
      ans=tmp;
      for(int i=0;i<n;i++) c[i]=a[i];
      for(int i=0;i<m;i++) d[i]=b[i];
    }
  }
  if(ans>=0){
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
      for(int j=0;j<c[i];j++)
	cout<<"row "<<i+1<<endl;
    for(int i=0;i<m;i++)
      for(int j=0;j<d[i];j++)
	cout<<"col "<<i+1<<endl;
  }else cout<<-1<<endl;
  return 0;
}