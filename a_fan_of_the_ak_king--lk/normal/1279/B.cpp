#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=1000005,M=998244353;
int n,i,t,a[N],e,ans,p,j;
long long s[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&e);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		p=0;
		for(i=1;i<=n;++i)
			if(s[i]>e)
				break;
		ans=i-1;
		int tmp=i;
		for(i=1;i<=tmp;++i)
		{
			for(j=ans+1;j<=n;++j)
				if(s[j]-a[i]>e)
					break;
			if(ans<j-2)
			{
				ans=j-2;
				p=i;
			}
		}
		printf("%d\n",p);
	}
}