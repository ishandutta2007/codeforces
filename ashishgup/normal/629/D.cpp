#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ctr=0;
int r[N], h[N], a[N], bit[N];
map<int, int> m, rm;

void update(int idx, int k)
{
	while(idx<=n)
	{
		bit[idx]=max(bit[idx], k);
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans=max(ans, bit[idx]);
		idx-=idx&-idx;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i]>>h[i];
		a[i]=r[i]*r[i]*h[i];
		m[a[i]];
	}
	for(auto &it:m)
	{
		it.second=++ctr;
		rm[ctr]=it.first;
	}
	for(int i=1;i<=n;i++)
		a[i]=m[a[i]];
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		int cur=pref(a[i]-1) + rm[a[i]];
		update(a[i], cur);
		ans=max(ans, (double)cur);
	}
	ans*=acosl(-1.0l);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}