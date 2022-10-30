#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;
typedef long long LL;
const LL mod = 1e9+7;

LL f[40][2][2][2];
LL g[40][2][2][2];
LL calc(int n,int m,int K)
{
	if (n<=0||m<=0||K<=0) return 0;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	
	f[31][0][0][0]=1;
	for (int i=30;i>=0;i--)
	{
		int ni=(n>>i)&1;
		int mi=(m>>i)&1;
		int Ki=(K>>i)&1;
		for (int j=0;j<=1;j++)
		for (int k=0;k<=1;k++)
		for (int l=0;l<=1;l++)
		if (LL c=f[i+1][j][k][l])
		{
			LL w=g[i+1][j][k][l];
			for (int ai=0;ai<=1;ai++)
			if (j||ai<=ni)
			for (int bi=0;bi<=1;bi++)
			if (k||bi<=mi)
			{
				int ci=ai^bi;
				if (l||ci<=Ki)
				{
					(f[i][j|(ai<ni)][k|(bi<mi)][l|(ci<Ki)]+=c)%=mod;
					(g[i][j|(ai<ni)][k|(bi<mi)][l|(ci<Ki)]+=w+c*(ci<<i))%=mod;
				}
			}
		}
	}
	return (f[0][1][1][1]+g[0][1][1][1])%mod;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("car.in","r",stdin);
		freopen("car.out","w",stdout);
	#endif
	int T;for (scanf("%d",&T);T--;)
	{
		int x1,y1,x2,y2,K;LL ans=0;
		scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&K);
		ans+=calc(x2,y2,K)+calc(x1-1,y1-1,K);
		ans-=calc(x2,y1-1,K)+calc(x1-1,y2,K);
		ans%=mod;printf("%lld\n",ans<0?ans+mod:ans);
	}
	return 0;
}