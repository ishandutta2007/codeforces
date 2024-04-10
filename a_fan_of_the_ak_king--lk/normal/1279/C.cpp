#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=1000005,M=998244353;
int n,i,t,a[N],b[N],m,p[N],mx;
long long ans;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			p[a[i]]=i;
		}
		mx=0;
		ans=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d",&b[i]);
			if(p[b[i]]>mx)
			{
				ans+=(p[b[i]]-i)*2;
				mx=p[b[i]];
			}
		}
		printf("%lld\n",ans+m);
	}
}