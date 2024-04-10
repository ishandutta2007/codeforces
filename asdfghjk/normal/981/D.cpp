#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,K,i,j,k,x;
ll a[65],w,u,s[65];
bool ok[65][65];
int main()
{
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		s[i]=s[i-1]+a[i];
	}
	for(i=60;i>=0;--i)
	{
		for(j=0;j<=n;++j)
			for(k=0;k<=K;++k)
				ok[j][k]=false;
		u=w|(1ll<<i);
		ok[0][0]=true;
		for(j=1;j<=n;++j)
			for(k=1;k<=K;++k)
				for(x=0;x<j;++x)
					if(ok[x][k-1]&&((s[j]-s[x])&u)==u)
					{
						ok[j][k]=true;
						break;
					}
		if(ok[n][K])
			w=u;
	}
	printf("%lld",w);
	return 0;
}