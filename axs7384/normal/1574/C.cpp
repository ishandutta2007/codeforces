#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<ll> s;
ll sum;
ll x,y;
int n,m;
ll tmp1,tmp2;
const ll inf=4e18;
inline ll work(ll a,ll b)
{
	// cout<<"?"<<a<<' '<<b<<' '<<max(0LL,x-a)+max(0LL,y-b)<<endl;
	return max(0LL,x-a)+max(0LL,y-b);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%lld",&x);
		sum+=x;
		s.insert(x);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%lld%lld",&x,&y);
		auto it=s.lower_bound(x);
		if (it==s.end())
			tmp1=inf;
		else
			tmp1=work(*it,sum-*it);
		if (it==s.begin())
			tmp2=inf;
		else
		{
			--it;
			tmp2=work(*it,sum-*it);
		}
		printf("%lld\n",min(tmp1,tmp2));
	}
	return 0;
}