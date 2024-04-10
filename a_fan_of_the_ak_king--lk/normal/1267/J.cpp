#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int t,n,c[2000005],f[2000005],p[4000005],ans,k,i,j;
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
			scanf("%d",&c[i]);
			++f[c[i]];
		}
		k=0;
		for(i=1;i<=n;++i)
			if(f[c[i]])
			{
				++p[f[c[i]]];
				++k;
				f[c[i]]=0;
			}
		for(i=1;i<=n*2;++i)
			p[i]+=p[i-1];
		ans=1<<30;
		for(i=2;i<=n;++i)
		{
			int s=0,op=0;
			for(j=i;j-i<=n;j+=i)
			{
				s+=p[j]-p[max(j/i*(i-1)-1,j-i)];
				op+=j/i*(p[j]-p[max(j/i*(i-1)-1,j-i)]);
			}
			if(s==k)
				ans=min(ans,op);
		}
		for(i=1;i<=n*2;++i)
			p[i]=0;
		if(n==1)
			puts("1");
		else
			cout<<ans<<endl;
	}
}