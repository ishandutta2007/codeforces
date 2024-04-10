#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N];

int check(int k)
{
	int have=0;
	if(a[n]>k)
		return 0;
	for(int i=1;i<=n;i++)
	{
		have+=k-a[i];
		if(have>=m)
			return 1;
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int ans1=binsearch(1, 1e9);
	int ans2=a[n]+m;
	cout<<ans1<<" "<<ans2;
	return 0;
}