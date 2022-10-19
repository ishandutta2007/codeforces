#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
const int mx=500;
ll f[N][mx+5];
ll a[N];
int t,n;
const ll inf=1e18;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for (int i=1;i<=n;++i)
			a[i]+=a[i-1];
		for (int i=1;i<=n+1;++i)
			f[i][0]=inf;
		for (int i=1;i<=mx;++i)
			f[n+1][i]=0;
		for (int i=n;i>=1;--i)
		{
			for (int j=1;j<=mx;++j)
			{
				f[i][j]=f[i+1][j];
				if (i+j-1<=n&&f[i+j][j-1]>a[i+j-1]-a[i-1])
					f[i][j]=max(f[i][j],a[i+j-1]-a[i-1]);
			}
		}
		int ans=0;
		for (int i=1;i<=mx;++i)
			if (f[1][i])
				ans=i;
		printf("%d\n",ans);
	}
	return 0;
}