#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,mx,i0=0,i1=1;
LL ans;
int c[26];
LL g[205][205];
LL f[2][205][205][3][3];
int main()
{
	scanf("%d",&n),mx=(n>>1)+1;
	for(int i=0;i<26;++i)scanf("%d",&c[i]);
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)f[0][(!i)+(!j)][(i==1)+(j==1)][i][j]+=(i==2? 24:1)*(j==2? 24:1);
	for(int i=3;i<=n;++i,i0^=1,i1^=1)
	{
		for(int j=0;j<=mx;++j)
			for(int k=0;k<=mx;++k)
				for(int l=0;l<3;++l)
					for(int o=0;o<3;++o)
						f[i1][j][k][l][o]=0;
		for(int j=0;j<=mx;++j)
			for(int k=0;k<=mx;++k)
				for(int l=0;l<3;++l)
					for(int o=0;o<3;++o)
						if(f[i0][j][k][l][o])
							(f[i1][j+1][k][o][0]+=f[i0][j][k][l][o]*(l>0))%=mod,(f[i1][j][k+1][o][1]+=f[i0][j][k][l][o]*(l!=1))%=mod,(f[i1][j][k][o][2]+=f[i0][j][k][l][o]*(24-(l==2)))%=mod;
	}
	for(int i=mx;~i;--i)
	{
		for(int j=mx;~j;--j)
		{
			for(int k=0;k<3;++k)for(int l=0;l<3;++l)g[i][j]+=f[i0][i][j][k][l];
			(g[i][j]+=g[i][j+1])%=mod;
		}
		for(int j=mx;~j;--j)(g[i][j]+=g[i+1][j])%=mod;
	}
	ans=g[0][0];
	for(int i=0;i<26;++i)
		if(c[i]<mx)
		{
			ans-=g[c[i]+1][0];
			for(int j=i+1;j<26;++j)if(c[j]<mx)ans+=g[c[i]+1][c[j]+1];
		}
	return 0&printf("%lld",((ans%mod)+mod)%mod);
}