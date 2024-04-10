#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, A, cf, cm, m, val=-1, curm;
pair<int, int> a[N];
int ans[N], need[N];

int check(int idx)
{
	return (need[idx]<=curm);
}

int binary_search(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	lo=max(lo, 1LL);
	return min(A, (a[lo].first + ((curm - need[lo])/lo)));
}

int32_t main()
{
	IOS;
	cin>>n>>A>>cf>>cm>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	a[n+1].first=A;
	for(int i=2;i<=n+1;i++)
		need[i]=need[i-1] + (i-1)*(a[i].first-a[i-1].first);
	int taken=0, storei=0, storeo=0;
	for(int i=0;i<=n;i++)
	{
		taken+=(A-a[n+1-i].first);
		if(m-taken<0)
			break;
		int rem=m-taken;
		curm=rem;
		int others=binary_search(0, n-i);
		if(i==n)
			others=A;
		if(i*cf + others*cm > val)
		{
			val=i*cf + others*cm;
			storei=i;
			storeo=others;
		}
	}
	for(int i=n+1-storei;i<=n;i++)
		ans[a[i].second]=A;
	for(int i=1;i<n+1-storei;i++)
		ans[a[i].second]=max(storeo, a[i].first);
	cout<<val<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}