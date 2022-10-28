#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, x, k, ans=0;
int a[N];

int find(int b)
{
	int next=b + k*x;
	if(b%x==0)
		next-=1;
	next-=next%x;
	return next;
}

int32_t main()
{
	IOS;
	cin>>n>>x>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
	{
		int lowest=find(a[i]);
		int highest=lowest+x-1;
		lowest=max(lowest, a[i]);
		auto it=lower_bound(a+1, a+n+1, lowest);
		auto it2=upper_bound(a+1, a+n+1, highest);
		ans+=it2-it;
	}
	cout<<ans;
	return 0;
}