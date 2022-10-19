#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
int a[N];
int n;
ll ans;
inline ll getmid(ll a,ll b,ll c,ll d)
{
	return max(0ll,min(b,d)-max(a,c)+1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i+=2)
	{
		ll mn=1,mx=a[i],now=0;
		for (int j=i+1;j<=n;j+=2)
		{
			ans+=getmid(mn,mx,now+1,now+a[j]);
			now+=a[j];
			mn=max(mn,now);
			now-=a[j+1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}