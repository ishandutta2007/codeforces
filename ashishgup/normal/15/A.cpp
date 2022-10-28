#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, t;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		int x, l;
		cin>>x>>l;
		a[i].first=2*x-l; //[x-l/2, x+l/2] 
		a[i].second=2*x+l; 
	}
	sort(a+1, a+n+1);
	int ans=2;
	for(int i=1;i<=n-1;i++)
	{
		if(a[i+1].first-a[i].second==2*t)
			ans++;
		else if(a[i+1].first-a[i].second>2*t)
			ans+=2;
	}
	cout<<ans;
	return 0;
}