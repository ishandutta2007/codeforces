#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, x1, y1, x2, y2, ans=1e18;
pair<int, int> a[N];
int x[N], y[N];

int dist(pair<int, int> &p1, pair<int, int> &p2)
{
	int xdiff=p1.first-p2.first;
	int ydiff=p1.second-p2.second;
	return xdiff*xdiff + ydiff*ydiff;
}

int32_t main()
{
	IOS;
	cin>>n>>x1>>y1>>x2>>y2;
	pair<int, int> p1={x1, y1};
	pair<int, int> p2={x2, y2};
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		pair<int, int> p={x[i], y[i]};
		a[i].first=dist(p1, p);
		a[i].second=dist(p2, p);
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n+1;i++)
	{
		int cur=0;
		for(int j=i;j<=n;j++)
			cur=max(cur, a[j].second);
		ans=min(ans, a[i-1].first+cur);
	}
	cout<<ans;
	return 0;
}