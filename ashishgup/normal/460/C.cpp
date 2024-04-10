#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+5;

long long a[N], bit[N];
int n,m,w;

void update(int i, int k)
{
	while(i<N)
	{
		bit[i]+=k;
		i+=(i&(-i));
	}
}

long long prefsum(int i)
{
	ll ans=0;
	while(i>0)
	{
		ans+=bit[i];
		i-=(i&(-i));
	}
	return ans;
}

bool check(ll k)
{
	ll count=0;
	for(int i=1;i<=n;i++)
	{
		long long curval=a[i] + prefsum(i);
		long long diff=max(0LL, k-curval);
		update(i, diff);
		update(i+w, -1*diff);
		count+=diff;
		if(count>m)
		{
			return 0;
		}
	}
	return 1;
}

long long binsearch(ll lo, ll hi)
{
	while(lo<hi)
	{
		memset(bit, 0, sizeof(bit));
		ll mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}
int main()
{
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long ans=binsearch(1, 1e15);
	cout<<ans;
	return 0;
}