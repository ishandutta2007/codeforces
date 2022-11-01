#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=505;
const int MOD=998244353;
const int ny2=(MOD+1)/2;

int n,k,f[N][N],val[N];

int dp(int w)
{
	for (int i=1;i<=w;i++) f[1][i]=0;
	f[1][1]=2;
	for (int i=2;i<=n;i++)
	{
		f[i][1]=0;
		for (int j=1;j<=w;j++) (f[i][1]+=f[i-1][j])%=MOD;
		for (int j=2;j<=w;j++) f[i][j]=f[i-1][j-1];
	}
	int ans=0;
	for (int i=1;i<=w;i++) (ans+=f[n][i])%=MOD;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) val[i]=dp(i);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int j=0;
		while (j<n&&(j+1)*i<k) j++;
		(ans+=(LL)(val[i]+MOD-val[i-1])*val[j]%MOD*ny2%MOD)%=MOD;
	}
	printf("%d\n",ans);
	return 0;
}