#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k, curh=0, ans=0;
int a[N], bit[N];

void update(int idx, int val)
{
	while(idx<=2e5)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>=1)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int l, int r)
{
	return pref(r) - pref(l-1);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(a[i], 1);
	}
	sort(a+1, a+n+1);
	int curcost=0;
	for(int i=2e5;i>=a[1];i--)
	{
		int temp=rsum(i+1, 2e5);	
		if(curcost+temp>k)
		{
			curcost=temp;
			ans++;
		}
		else 
			curcost+=temp;
	}
	if(curcost)
		ans++;
	cout<<ans;
	return 0;
}