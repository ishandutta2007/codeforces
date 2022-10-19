#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int n,p;
LL ans=0;
int c[52];
LL pw[52];
LL f[52][3][3][3][3];
inline int up(int x)
{
	return (++x)>2? 1:x;
}
int main()
{
	scanf("%d%d",&n,&p),pw[0]=f[0][0][0][0][0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&c[i]),pw[i]=(pw[i-1]<<1)%mod;
	for(int i=0;i<n;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				for(int l=0;l<3;++l)
					for(int o=0;o<3;++o)
						if(f[i][j][k][l][o])
						{
							if(c[i+1])
							{
								if(!k)(f[i+1][up(j)][k][l][o]+=f[i][j][k][l][o]*pw[i])%=mod;
								else (f[i+1][up(j)][k][l][o]+=f[i][j][k][l][o]*pw[i-1])%=mod,(f[i+1][j][k][up(l)][o]+=f[i][j][k][l][o]*pw[i-1])%=mod;
							}
							if(c[i+1]^1)
							{
								if(!j)(f[i+1][j][up(k)][l][o]+=f[i][j][k][l][o]*pw[i])%=mod;
								else (f[i+1][j][up(k)][l][o]+=f[i][j][k][l][o]*pw[i-1])%=mod,(f[i+1][j][k][l][up(o)]+=f[i][j][k][l][o]*pw[i-1])%=mod;
							}
						}
	for(int j=0;j<3;++j)
		for(int k=0;k<3;++k)
			for(int l=0;l<3;++l)
				for(int o=0;o<3;++o)
					if(!((j^k^p)&1) && f[n][j][k][l][o])
						(ans+=f[n][j][k][l][o])%=mod;
	return 0&printf("%lld",ans);
}