#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int a, x, y;

void yes(int ans)
{	
	cout<<ans;
	exit(0);
}

void no()
{
	cout<<"-1";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>a>>x>>y;
	if(x>=a || x<=-a || y%a==0)
		no();
	if(y<a)
	{
		if(2*x>=a || 2*x<=-a)
			no();
		yes(1);
	}
	int idx=(y-a)/a;
	if(idx%2==0)
	{
		if(2*x>=a || 2*x<=-a)
			no();
		yes(2 + 3*((y-a)/(2*a)));
	}
	else
	{
		if(x<=-a || x>=a  || x==0)
			no();
		if(x<0)
			yes(3 + 3*((y-a)/(2*a)));
		else
			yes(4 + 3*((y-a)/(2*a)));
	}
	return 0;
}