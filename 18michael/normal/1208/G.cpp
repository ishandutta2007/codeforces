#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,p_t=0;
LL ans=6;
int p[1000002],phi[1000002];
inline void init()
{
	for(int i=2;i<=n;++i)
	{
		if(!phi[i])p[++p_t]=i,phi[i]=i-1;
		for(int j=1;j<=p_t && p[j]<=n/i;++j)
		{
			if(!(i%p[j]))
			{
				phi[p[j]*i]=phi[i]*p[j];
				break;
			}
			phi[p[j]*i]=phi[i]*(p[j]-1);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1)return 0&puts("3");
	if(k==2)return 0&puts("6");
	init(),sort(phi+5,phi+n+1);
	for(int i=5;i<=k+2;++i)ans+=phi[i];
	return 0&printf("%lld",ans);
}