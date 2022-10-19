#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n;
LL ans=0,res=1;
LL f[12][702][702][2];
char s[702];
inline void upd(LL &x,LL y)
{
	if((x+=y)>=mod)x-=mod;
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<10;++i)f[i][0][0][1]=1;
	for(int i=1,x;i<=n;++i)
	{
		x=(s[i]^48);
		for(int j=1;j<10;++j)
			for(int k=0;k<i;++k)
			{
				upd(f[j][i][k][0],(f[j][i-1][k][0]*j)%mod),upd(f[j][i][k+1][0],(f[j][i-1][k][0]*(10-j))%mod);
				if(f[j][i-1][k][1])
				{
					for(int o=0;o<x;++o)upd(f[j][i][k+(o>=j)][0],f[j][i-1][k][1]);
					upd(f[j][i][k+(x>=j)][1],f[j][i-1][k][1]);
				}
			}
	}
	for(int i=1;i<=n;++i,res=(res*10+1)%mod)for(int j=1;j<10;++j)ans=(ans+(f[j][n][i][0]+f[j][n][i][1])*res)%mod;
	return 0&printf("%lld",ans);
}