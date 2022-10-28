#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
int a[N], b[N], idx[N], bit[N];

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]=max(bit[idx], val);
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
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		idx[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
		a[i]=idx[a[i]];
	reverse(a+1, a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int cur=pref(a[i])+1;
		ans=max(ans, cur);
		update(a[i], cur);
	}
	cout<<ans;
	return 0;
}