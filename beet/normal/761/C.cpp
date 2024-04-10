#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2][2][2][100];
int main(){
  int n,m;
  cin>>n>>m;
  string s[n];
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=0;i<=n;i++)
    for(int a=0;a<2;a++)
      for(int b=0;b<2;b++)
	for(int c=0;c<2;c++)
	  dp[a][b][c][i]=1<<25;
  dp[0][0][0][0]=0;
  for(int i=0;i<n;i++)
    for(int a=0;a<2;a++)
      for(int b=0;b<2;b++)
	for(int c=0;c<2;c++)
	  for(int j=0;j<m;j++){
	    bool d=isdigit(s[i][j]);
	    bool e=isalpha(s[i][j]);
	    bool f=(!d)&&(!e);
	    dp[a|d][b|e][c|f][i+1]=
	      min(dp[a|d][b|e][c|f][i+1],dp[a][b][c][i]+min(j,m-j));
	    
	    //cout<<(a|d)<<" "<<(b|e)<<" "<<(c|f)<<" "<<(i+1)<<":";
	    //cout<<dp[a|d][b|e][c|f][i+1]<<endl;
	  }
  cout<<dp[1][1][1][n]<<endl;
  return 0;
}