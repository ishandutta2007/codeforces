#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,t;
int a[N];
#define ll long long
ll k;
ll f[N];
ll ans;
const ll inf=2e18;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%lld",&n,&k);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		f[0]=0;
		for (int i=1;i<n;++i)
			f[i]=f[i-1]+a[i];
		ans=inf;
		for (int i=0;i<n;++i)
		{
			int ti=n-i;
			ll x=floor(((double)k-f[i])/(double)ti);
			ll dx=max(0LL,a[0]-x);
			ans=min(ans,dx+ti-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}