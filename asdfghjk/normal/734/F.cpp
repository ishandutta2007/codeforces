#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=400005;
ll n,a[N],b[N],c[N],s,w[N],i,j,x,y;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",b+i);
		s+=b[i];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%lld",c+i);
		s+=c[i];
	}
	if(s%(2*n))
	{
		printf("-1");
		return 0;
	}
	s/=2*n;
	for(i=1;i<=n;++i)
	{
		if(b[i]+c[i]-s>=0&&(b[i]+c[i]-s)%n==0)
			a[i]=(b[i]+c[i]-s)/n;
		else
		{
			printf("-1");
			return 0;
		}
	}
	for(i=1;i<=n;++i)
		for(j=0;j<=30;++j)
			if(a[i]>>j&1)
				w[j]++;
	for(i=1;i<=n;++i)
	{
		if(a[i]>=(1<<30))
		{
			printf("-1");
			return 0;
		}
		x=y=0;
		for(j=0;j<=30;++j)
			if(a[i]>>j&1)
				x+=(1ll<<j)*w[j],y+=(1ll<<j)*n;
			else
				y+=(1ll<<j)*w[j];
		if(x!=b[i]||y!=c[i])
		{
			printf("-1");
			return 0;
		}
	}
	for(i=1;i<=n;++i)
		printf("%lld ",a[i]);
	return 0;
}