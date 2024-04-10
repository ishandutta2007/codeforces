#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int long long
const int N=10000+10;
const int MOD=1e9+7;

int n,m,a[N],l[N],r[N];
int b[N<<1],tot,dp[4][N<<1],mp[4][N<<1];

int X[4][4],Y[4][4],R[4][4];

void quickpow(int y)
{
	memset(R,0,sizeof R);
	R[1][1]=R[2][2]=R[3][3]=1;
	int i,j,k;
	while(y)
	{
		if(y&1)
		{
			for(i=1;i<=3;++i)
				for(j=1;j<=3;++j)
				{
					Y[i][j]=0;
					for(k=1;k<=3;++k)
						(Y[i][j]+=X[i][k]*R[k][j]%MOD)%=MOD;
				}
			memcpy(R,Y,sizeof Y);
		}
		y>>=1;
		for(i=1;i<=3;++i)
			for(j=1;j<=3;++j)
			{
				Y[i][j]=0;
				for(k=1;k<=3;++k)
					(Y[i][j]+=X[i][k]*X[k][j]%MOD)%=MOD;
			}
		memcpy(X,Y,sizeof Y);
	}
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	int i,j,rec1,rec2,rec3;
	for(i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",a+i,l+i,r+i);
		b[++tot]=l[i];
		if((++r[i])<=m)
			b[++tot]=r[i];
	}
	b[++tot]=1;
	b[++tot]=m;
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(i=1;i<=n;++i)
	{
		++mp[a[i]][lower_bound(b+1,b+tot+1,l[i])-b];
		if(r[i]<=m)
			--mp[a[i]][lower_bound(b+1,b+tot+1,r[i])-b];
	}
	for(i=1;i<=3;++i)
		for(j=1;j<=tot;++j)
			mp[i][j]+=mp[i][j-1];
	if(mp[2][1]||mp[2][tot])
	{
		printf("0");
		return 0;
	}
	dp[2][1]=1;
	for(i=1;i<tot;++i)
	{
		memset(X,0,sizeof X);
		if(!mp[1][i])
			X[1][1]=X[1][2]=1;
		if(!mp[2][i])
			X[2][1]=X[2][2]=X[2][3]=1;
		if(!mp[3][i])
			X[3][2]=X[3][3]=1;
		quickpow(b[i+1]-b[i]-1);
		rec1=dp[1][i];rec2=dp[2][i];rec3=dp[3][i];
		dp[1][i]=(R[1][1]*rec1%MOD+R[1][2]*rec2%MOD+R[1][3]*rec3%MOD)%MOD;
		dp[2][i]=(R[2][1]*rec1%MOD+R[2][2]*rec2%MOD+R[2][3]*rec3%MOD)%MOD;
		dp[3][i]=(R[3][1]*rec1%MOD+R[3][2]*rec2%MOD+R[3][3]*rec3%MOD)%MOD;
		if(!mp[1][i+1])dp[1][i+1]=(dp[1][i]+dp[2][i])%MOD;
		if(!mp[2][i+1])dp[2][i+1]=(dp[1][i]+dp[2][i]+dp[3][i])%MOD;
		if(!mp[3][i+1])dp[3][i+1]=(dp[2][i]+dp[3][i])%MOD;
	}
	printf("%lld",dp[2][tot]);
	return 0;
}