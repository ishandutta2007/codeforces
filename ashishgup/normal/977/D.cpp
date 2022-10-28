#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, x, y;
int a[N];
vector<int> g[N];

int calc3(int x)
{
	int ct=0;
	while(x%3==0 && x>0)
	{
		ct++;
		x/=3;
	}
	return ct;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[calc3(a[i])].push_back(a[i]);
		x=min(x, calc3(a[i]));
		y=max(y, calc3(a[i]));
	}
	for(int i=x;i<=y;i++)
	{
		sort(g[i].begin(), g[i].end());
	}
	for(int i=y;i>=x;i--)
	{
		for(auto it:g[i])
			cout<<it<<" ";
	}
	return 0;
}