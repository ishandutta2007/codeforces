#include <bits/stdc++.h>
using namespace std;
#define make(dp,ar,q,w,e,r,t,y,a,s,d,f)memset(dp,0,sizeof(dp));\
for(int i=q;w;e)for(int j=r;t;y)dp[i][j]=max(dp[i+a][j+s],dp[i+d][j+f])+ar[i][j];
int n,m,ar[1002][1002],dp[4][1002][1002],ans,i,j;
int main(){
	cin >>n>> m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>ar[i][j];
	make(dp[0],ar,1,i<=n,i++,1,j<=m,j++,-1,0,0,-1);
	make(dp[1],ar,1,i<=n,i++,m,j,j--,-1,0,0,1);
	make(dp[2],ar,n,i,i--,m,j,j--,1,0,0,1);
	make(dp[3],ar,n,i,i--,1,j<= m,j++,1,0,0,-1);
	for(i=2;i<n;i++)for(j=2;j<m;j++)ans=max(ans,max(dp[0][i-1][j]+dp[2][i+1][j]+dp[3][i][j-1]+dp[1][i][j+1],dp[3][i+1][j]+dp[1][i-1][j]+dp[0][i][j-1]+dp[2][i][j+1]));
	cout << ans;
}