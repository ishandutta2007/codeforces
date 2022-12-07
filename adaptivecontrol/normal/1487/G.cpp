#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,ans=676,dp[2][203][203],dp2[3][203][203][203],a[26],dp3[203][203];
long long C(long long x,long long y){return (dp[0][x][y]+dp[1][x][y])%mod;}
long long C2(long long x,long long y,long long z){
	return (dp2[0][x][y][z]+dp2[1][x][y][z]+dp2[2][x][y][z])%mod;}
bool vis[203][203];
int main(){
	cin>>n;
	for(int i=2;i<n;i++)ans=ans*25%mod;
	dp[0][1][1]=1;dp[1][1][0]=25; 
	for(int i=2;i<=(n+1)/2;i++){
		for(int j=0;j<203;j++)
			dp[1][i][j]=(dp[0][i-1][j]*25+dp[1][i-1][j]*24)%mod;
		for(int j=1;j<203;j++)
			dp[0][i][j]=dp[1][i-1][j-1];
	}dp2[2][1][0][0]=24;dp2[1][1][0][1]=1;dp2[0][1][1][0]=1;
	for(int i=2;i<=(n+1)/2;i++){
		for(int j=0;j<203;j++)
			for(int k=0;k<203;k++)
				dp2[2][i][j][k]=(dp2[0][i-1][j][k]*24+dp2[1][i-1][j][k]*24+dp2[2][i-1][j][k]*23)%mod;
		for(int j=1;j<203;j++)
			for(int k=0;k<203;k++)
				dp2[0][i][j][k]=(dp2[1][i-1][j-1][k]+dp2[2][i-1][j-1][k])%mod;
		for(int j=0;j<203;j++)
			for(int k=1;k<203;k++)
				dp2[1][i][j][k]=(dp2[0][i-1][j][k-1]+dp2[2][i-1][j][k-1])%mod;
	}
	for(int i=0;i<26;i++){
		scanf("%d",a+i);
		for(int y=a[i]+1;y<=201;y++)
			for(int j=0;j<=y;j++)
				ans=(ans-C(n/2,j)*C((n+1)/2,y-j)%mod+mod)%mod;
	}
	for(int i=0;i<26;i++)
		for(int j=i+1;j<26;j++)
			for(int y=a[i]+1;y<=201;y++)
				for(int Y=a[j]+1;Y<=201;Y++){
					if(vis[y][Y]){ans=(ans+dp3[y][Y])%mod;continue;}vis[y][Y]=1;
					for(int k=0;k<=y;k++)
						for(int l=0;l<=Y;l++)
							dp3[y][Y]=(dp3[y][Y]+C2(n/2,k,l)*C2((n+1)/2,y-k,Y-l))%mod;
					ans=(ans+dp3[y][Y])%mod;
//					if(dp3[y][Y])cout<<y<<' '<<Y<<' '<<dp3[y][Y]<<endl;
				}
	cout<<ans;
}