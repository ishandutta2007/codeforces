#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int p;
  cin>>p;
  int sum=0;
  for(int i=0;i<n;i++) sum+=a[i];
  if(sum<=p){
    cout<<n<<endl;
    return 0;
  }
  double b[n+1];
  double c=0;
  b[0]=1.0;
  for(int i=0;i<n;i++) b[i+1]=b[i]*(i+1);
  int dp[100][100];
  for(int i=0;i<n;i++){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int j=0;j<n;j++){
      if(i==j) continue;
      for(int k=n-1;k>=0;k--){
	for(int l=p;l>=a[j];l--){
	  dp[k+1][l]+=dp[k][l-a[j]];
	}
      }
    }
    for(int j=0;j<=p;j++){
      if(j+a[i]<=p) continue;
      for(int k=0;k<n;k++)
	c+=dp[k][j]*k*b[k]*b[n-1-k];
    }
  }
  printf("%.12f\n",c/b[n]);
  return 0;
}