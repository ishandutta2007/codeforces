#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,ans=0;
int p[252],q[252],cnt[3],rt[252];
bool u[252];
LL A[252][252],C[252][252],S[252][252],f[3][252],dp[3][252];
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	scanf("%d",&n),A[0][0]=C[0][0]=S[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		rt[i]=i,A[i][0]=C[i][0]=1;
		for(int j=1;j<=i;++j)A[i][j]=(A[i][j-1]*(i-j+1))%mod,C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod,S[i][j]=(S[i-1][j-1]+S[i-1][j]*(i-1))%mod;
	}
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&q[i]);
		if(!p[i] && !q[i])++cnt[2];
		else if(p[i] && q[i])
		{
			getroot(p[i]),getroot(q[i]);
			if(rt[p[i]]==rt[q[i]])++ans;
			else rt[rt[p[i]]]=rt[q[i]];
		}
		else
		{
			if(p[i])++cnt[0];
			if(q[i])++cnt[1];
		}
	}
	for(int i=1;i<=n;++i)getroot(i);
	for(int i=1;i<=n;++i)if(!p[i])u[rt[q[i]]]=1;
	for(int i=1;i<=n;++i)if(!q[i] && p[i] && u[rt[p[i]]])++cnt[2],--cnt[0],--cnt[1];
	for(int o=0;o<2;++o)for(int i=0;i<=n;++i)for(int j=i;j<=cnt[o];++j)(f[o][i]+=((C[cnt[o]][j]*S[j][i])%mod)*(j==cnt[o]? 1:A[cnt[o]-j+cnt[2]-1][cnt[o]-j]))%=mod;
	for(int i=0;i<=n;++i)f[2][i]=(S[cnt[2]][i]*A[cnt[2]][cnt[2]])%mod,dp[0][i]=f[0][i];
	for(int o=1;o<3;++o)for(int i=0;i<=n;++i)for(int j=0;j+i<=n;++j)(dp[o][j+i]+=f[o][i]*dp[o-1][j])%=mod;
	for(int i=n;i;--i)printf("%lld ",i<ans? 0:dp[2][i-ans]);
	return 0;
}