#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e12;
int t,n,x;
ll a[100005],mx[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&x);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for (int i=1;i<=n;++i)
			a[i]+=a[i-1];
		for (int i=1;i<=n;++i)
			mx[i]=-inf;
		mx[0]=0;
		for (int i=1;i<=n;++i)
			for (int j=i;j<=n;++j)
				mx[j-i+1]=max(mx[j-i+1],a[j]-a[i-1]);
		for (int i=n-1;i>=0;--i)
			mx[i]=max(mx[i+1],mx[i]);
		ll ans=0;
		for (int i=0;i<=n;++i)
		{
			ans=max(ans,mx[i]+(ll)i*x);
			printf("%lld ",ans);
		}
		puts("");
	}
	return 0;
}