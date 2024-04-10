#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int x, y, m;
	cin>>x>>y>>m;
	if(max(x, y)>=m)
	{
		cout<<"0";
		return 0;
	}
	if(max(x, y)<=0)
	{
		cout<<"-1";
		return 0;
	}
	int ans=0;
	while(x<m && y<m)
	{
		if(x>y)
			swap(x, y);
		if(x<0)
		{
			int needed=(0-x+y-1)/y;
			ans+=needed;
			x+=needed*y;
		}
		else
		{
			x=x+y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}