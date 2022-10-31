#include<bits/stdc++.h>
using namespace std; 
const int N=200005,M=1000000007;
const long double PI=3.1415926535897932384626;
int n,m,i,t,k,a[N],s[N],p[N],f[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&m);
		for(i=1;i<=n;++i)
			f[i]=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d",&a[i]);
			f[a[i]]=1;
		}
		if((n-m)%(k-1)!=0)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;++i)
			s[i]=s[i-1]+(f[i]^1);
		p[m+1]=0;
		for(i=n;i>=1;--i)
			p[i]=p[i+1]+(f[i]^1);
		for(i=1;i<=m;++i)
			if(s[a[i]]>=k/2&&p[a[i]]>=k/2)
			{
				puts("YES");
				break;
			}
		if(i>m)
			puts("NO");
	}
}