#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,p[N],l,mn1[N],mn2[N],c[N],i,j,k,id[N],a[N];
bool v[N];
long long ans;
int main()
{
	scanf("%d",&n);
	for(i=2;i<=200000;++i)
	{
		if(!v[i])
		{
			p[++l]=i;
			id[i]=l;
		}
		for(j=1;j<=l&&p[j]*i<=200000;++j)
		{
			v[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	for(i=1;i<=l;++i)
		mn1[i]=mn2[i]=100;
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		for(j=1;j<=l&&1ll*p[j]*p[j]<=a[i];++j)
			if(a[i]%p[j]==0)
			{
				c[j]++;
				k=0;
				while(a[i]%p[j]==0)
					a[i]/=p[j],++k;
				if(k<mn1[j])
				{
					mn2[j]=mn1[j];
					mn1[j]=k;
				}
				else if(k<mn2[j])
					mn2[j]=k;
			}
		if(a[i]>1)
		{
			j=id[a[i]],k=1;
			c[j]++;
			if(k<mn1[j])
			{
				mn2[j]=mn1[j];
				mn1[j]=k;
			}
			else if(k<mn2[j])
				mn2[j]=k;
		}
	}
	for(i=1;i<=l;++i)
		if(c[i]<=n-2)
			mn1[i]=mn2[i]=0;
		else if(c[i]==n-1)
		{
			mn2[i]=mn1[i];
			mn1[i]=0;
		}
	ans=1;
	for(i=1;i<=l;++i)
		for(j=1;j<=mn2[i];++j)
			ans*=p[i];
	printf("%lld",ans);
	return 0;
}