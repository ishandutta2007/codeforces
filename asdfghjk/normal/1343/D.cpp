#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int t,n,K,i,a[N],c[N],w[N],ans,mx;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&K);
		for(i=0;i<=2*K;++i)
			w[i]=c[i]=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			c[a[i]+1]--,c[a[i]+K+1]++;
		}
		for(i=1;i<=n/2;++i)
		{
			c[max(a[i],a[n-i+1])+1]++,c[min(a[i],a[n-i+1])+K+1]--;
			w[a[i]+a[n-i+1]]++;
		}
		for(i=1;i<=2*K;++i)
			c[i]+=c[i-1];
		ans=n;
		for(i=1;i<=2*K;++i)
			ans=min(ans,n+c[i]-w[i]);
		printf("%d\n",ans);
	}
	return 0;
}