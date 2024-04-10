#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long f[2][405][405];
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	if(n>m)
	{
		printf("0\n");
		return 0;
	}
	int gs=0;
	f[gs][0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)for(int k=0;k<=j;k++)
			f[gs][j][k]%=mod,f[gs^1][j][k]=0;
		for(int j=0;j<=n;j++)for(int k=0;k<=j;k++)
		{
			if(i!=x)f[gs^1][j][k]+=f[gs][j][k];
			if(i!=x&&j>k)f[gs^1][j][k+1]+=f[gs][j][k];
			f[gs^1][j+1][k+1]+=f[gs][j][k];
			f[gs^1][j+1][k]+=f[gs][j][k];
		}
		gs^=1;
	}
	int ans=f[gs][n][n]%mod;
	for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
	cout<<ans<<endl;
	return 0;
}