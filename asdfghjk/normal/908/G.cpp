#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
char s[705];
int f[705][705][2],ans,i,j,k,x,pw[15][705],num[705],l,w[705],u[705],dp[705][705][2],jc[705],rjc[705],inv[705],Dp[705][705];
bool v[705][705][2];
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int dfs(int x,int y,bool t)
{
	if(!s[x])
		return 0;
	if(v[x][y][t])
		return f[x][y][t];
	int up=(t?s[x]-'0':9),rtn=0;
	for(int j=0;j<=up;++j)
	{
		int k=dfs(x+1,y+(j>=i),t&&j==up);
		if(j==i)
			k=(k+1ll*i*pw[10][y]%md*(t&&j==up?u[x+1]:w[x+1]))%md;
		rtn=(rtn+k)%md;
	}
	f[x][y][t]=rtn;
	v[x][y][t]=true;
	return rtn;
}
int main()
{
	scanf("%s",s+1);
	inv[1]=1;
	for(i=2;i<=700;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=700;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	for(i=0;i<=10;++i)
	{
		pw[i][0]=1;
		for(j=1;j<=700;++j)
			pw[i][j]=1ll*pw[i][j-1]*i%md;
	}
	l=strlen(s+1);
	for(i=l;i>=1;--i)
		num[i]=(num[i+1]+1ll*(s[i]-'0')*pw[10][l-i])%md;
	for(i=1;i<=9;++i)
	{
		for(int i=0;i<=702;++i)
			for(int j=0;j<=702;++j)
			{
				v[i][j][0]=v[i][j][1]=false;
				dp[i][j][0]=dp[i][j][1]=0;
			}
		dp[l+1][0][0]=1;
		for(j=l+1;j>=2;--j)
			for(k=0;k<=l+1-j;++k)
				for(x=0;x<=9;++x)
				{
					if(dp[j][k][0])
						dp[j-1][k+(x>i)][x>s[j-1]-'0']=(dp[j-1][k+(x>i)][x>s[j-1]-'0']+dp[j][k][0])%md;
					if(dp[j][k][1])
						dp[j-1][k+(x>i)][x>=s[j-1]-'0']=(dp[j-1][k+(x>i)][x>=s[j-1]-'0']+dp[j][k][1])%md;
				}
		for(j=1;j<=l+1;++j)
		{
			w[j]=u[j]=0;
			for(k=0;k<=l+1-j;++k)
			{
				u[j]=(u[j]+1ll*dp[j][k][0]*pw[10][k]%md)%md;
				w[j]=(w[j]+1ll*(dp[j][k][0]+dp[j][k][1])%md*pw[10][k]%md)%md;
			}
		}
		ans=(ans+dfs(1,0,true))%md;
	}
	printf("%d",ans);
	return 0;
}