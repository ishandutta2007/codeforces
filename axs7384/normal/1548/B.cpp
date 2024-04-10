#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define ll long long
ll f[20][N];
ll a[N];
int t,n;
int lg[N];
inline ll ask(int l,int r)
{
	int len=r-l+1;
	int p=lg[len];
	return __gcd(f[p][l],f[p][r+1-(1<<p)]);
}
inline bool ck(int x)
{
	for (int i=1;i+x-1<=n;++i)
		if (ask(i,i+x-1)!=1)
			return 1;
	return 0;
}
int main()
{
	lg[1]=0;
	for (int i=2;i<=200000;++i)
		lg[i]=lg[i/2]+1;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%lld",&a[i]);
		for (int i=1;i<n;++i)
			f[0][i]=abs(a[i]-a[i+1]);
		--n;
		for (int i=1;i<=17;++i)
			for (int j=1;j+(1<<i)-1<=n;++j)
				f[i][j]=__gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		int l=1,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (ck(mid))
				l=mid+1;
			else
				r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}