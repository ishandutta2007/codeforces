#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int x = 0;

int get(int x, int y)
{
	int ct = 0;
	while(x%y==0)
	{
		x /= y;
		ct++;
	}
	return ct;
}

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	int ans1 = get(b, 3) - get(a, 3);
	int ans2 = get(b, 2) - get(a, 2);
	if(ans1 >=0 && ans2 >= 0)
	{
		int store = ans1 + ans2;
		int cur = a;
		while(ans1 > 0)
		{
			cur *= 3;
			ans1--;
		}
		while(ans2 > 0)
		{
			cur *= 2;
			ans2--;
		}	
		if(cur == b)
			cout<<store;
		else
			cout<<"-1";
	}
	else
		cout<<"-1";
	return 0;
}