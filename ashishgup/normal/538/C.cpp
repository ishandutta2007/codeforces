#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0;
int d[N], h[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>d[i]>>h[i];
	for(int i=2;i<=m;i++)
	{
		int maxdiff=abs(d[i]-d[i-1]);
		if(abs(h[i]-h[i-1])>maxdiff)
		{
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	ans=max(h[1] + abs(d[1]-1), h[m] + abs(n-d[m]));
	for(int i=1;i<=m-1;i++)
	{
		int extradays=d[i+1] - d[i] - abs(h[i+1] - h[i]);
		int maxh=max(h[i], h[i+1]);
		ans=max(ans, maxh + extradays/2);
	}
	cout<<ans;
	return 0;
}