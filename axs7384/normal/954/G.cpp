#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int N=1000005;
ll a[N],f[N],K,ans;
int n,r;
inline void read(int &x)
{
	x=0;	
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void readll(ll &x)
{
	x=0;	
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline bool check(ll k)
{
	ll ans=0,sum=0;
	memset(f,0,sizeof(f));
	for (int i=1;i<=r;++i)
		sum+=a[i];
	for (int i=r+1;i<=n+r;++i)
	{
		sum+=a[i];
		if (i>r*2+1)
			sum-=a[i-r*2-1]+f[i-r*2-1];
		if (sum<k)
		{
			f[i]=k-sum;
			ans+=k-sum;
			sum=k;
		}
		if (ans>K)
			return 0;
	}
	return ans<=K;
}
signed main()
{
	read(n);
	read(r);
	if (r>=n)
		r=n-1;
	readll(K);
	for (int i=1;i<=n;++i)
		readll(a[i]);
	ans=0;
	ll l=0,r=2e18;
	while (l<=r)
	{
		ll mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	cout<<ans;
}