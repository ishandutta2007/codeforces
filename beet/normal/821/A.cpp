#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i][j]==1) continue;
      bool flg=0;
      for(int s=0;s<n;s++)
	for(int t=0;t<n;t++)
	  flg|=(a[i][s]+a[t][j]==a[i][j]);
      if(!flg){
	cout<<"No"<<endl;
	return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}