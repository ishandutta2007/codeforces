#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ctr=1;
int a[N], bit[N];
map<int, int> m;

void update(int i, int x)
{
	while(i<=n)
	{
		bit[i]=max(bit[i], x);
		i+=(i&(-i));
	}
}

int prefmax(int i)
{
	int ans=0;
	while(i>0)
	{
		ans=max(ans, bit[i]);
		i-=(i&(-i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]];
	}
	for(auto &it:m)
	{
		it.second=ctr++;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=m[a[i]];
	}
	m.clear();
	for(int i=1;i<=n;i++)
	{
		update(a[i], i);
	}
	for(int i=1;i<=n;i++)
	{
		int last=prefmax(a[i]-1);
		if(last<i)
			cout<<"-1 ";
		else
			cout<<last-i-1<<" ";
	}
	return 0;
}