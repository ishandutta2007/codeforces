#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int xx, hh, yy;

int check(int x, int y)
{
	while(x>0)
	{
		if(x%10 == 7)
			return 1;
		x/=10;
	}
	while(y>0)
	{
		if(y%10 == 7)
			return 1;
		y/=10;
	}
	return 0;
}

void reduce(int &x, int &y)
{
	y-=xx;
	if(y<0)
	{
		y+=60;
		x--;
		if(x<0)
			x=23;
	}
}

int32_t main()
{
	IOS;
	cin>>xx>>hh>>yy;
	int ans=0;
	while(!check(hh, yy))
	{
		reduce(hh, yy);
		ans++;
	}
	cout<<ans;
	return 0;
}