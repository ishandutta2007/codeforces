#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;  

int n, h, ans=0;
int l[N], r[N], diff[N], pref[N];

int check(int idx, int k)
{
	int dropped=diff[k]-diff[idx-1];
	return dropped<h;
}

int binsearch(int idx, int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(idx, mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>h;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		pref[i]=pref[i-1] + (r[i]-l[i]);
	}
	for(int i=1;i<=n;i++)
	{
		diff[i]=l[i+1]-r[i];
		diff[i]+=diff[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		int cur=h;
		int get=binsearch(i, i-1, n-1);
		cur+=pref[get+1]-pref[i-1];
		ans=max(ans, cur);
	}
	cout<<ans;
	return 0;
}