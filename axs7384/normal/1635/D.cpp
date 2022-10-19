#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
int n,p;
int a[200005];
// map<int,int> mp;
set<int> s;
int f[200005];
inline void insert(int x)
{
	// cout<<x<<' ';
	int y=x;
	while (x)
	{
		if (s.count(x))
			return;
		if (x&1)
			x>>=1;
		else
		{
			if (x&2)
			{
				s.insert(y);
				return;
			}
			else
				x>>=2;
		}
	}
	s.insert(y);
}
signed main()
{
	scanf("%lld%lld",&n,&p);
	for (int i=1,x;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		// insert(x);
		// int p=findroot(x);
		// // cout<<p<<endl;
		// if (mp[p]!=0)
		// 	mp[p]=min(mp[p],x);
		// else
		// 	mp[p]=x;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;++i)
		insert(a[i]);
	for (auto p: s)
	{
		// cout<<"?"<<p.first<<' '<<p.second<<' '<<(int)log2(p.second)<<endl;
		// ++f[(int)log2(p.second)];
		int q=p,sum=0;
		while (q>1)
		{
			q/=2;
			++sum;
		}
		++f[sum];
	}
	(f[1]+=f[0])%=mod;
	for (int i=2;i<p;++i)
		(f[i]+=(f[i-1]+f[i-2])%mod)%=mod;
	int ans=0;
	for (int i=0;i<p;++i)
	{
		// cout<<i<<' '<<f[i]<<endl;
		(ans+=f[i])%=mod;
	}
	cout<<ans<<endl;
	return 0;
}