//#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define inf 999999999
#define P 998244353
using namespace std;
int n,m,dp[5001][5001],s[5001][5001],ans;
string a,b;
signed main(){
	cin>>n>>m;
	cin>>a>>b;
//	a.insert('@',0),b.insert('@',0);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=s[i][j]=-inf;
	dp[0][0]=0;
//	for(int i=0;i<=n;i++)s[i][0]=i;
//	for(int i=0;i<=m;i++)s[0][i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=max(s[i-1][j],s[i][j-1]);
			if(a[i-1]==b[j-1]){
				dp[i][j]=max(s[i-1][j-1]+4-i-j,2);
				s[i][j]=max(s[i][j],dp[i][j]+i+j);
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans=max(ans,dp[i][j]);
	cout<<ans<<endl;
	return 0;
}
/*

*/