#include<bits/stdc++.h>
using namespace std; 
const int N=300005,M=998244353;
const long double PI=3.1415926535897932384626;
int n,i,t,f[N],a[N],j,ans,k,p[N],u,v;
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			f[i]=0;
		}
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			++f[u],++f[v];
		}
		k=0;
		long long ans=0;
		for(i=1;i<=n;++i)
		{
			ans+=a[i];
			while(f[i]>1)
			{
				--f[i];
				p[++k]=a[i];
			}
		}
		sort(p+1,p+1+k);
		printf("%lld ",ans);
		for(i=k;i>=1;--i)
		{
			ans+=p[i];
			printf("%lld ",ans);
		}
		printf("\n");
	}
}