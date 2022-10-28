#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int l, r, d;
		cin>>l>>r>>d;
		if(d<l)
			cout<<d<<endl;
		else
		{
			int y=r/d;
			int x=y*d;
			while(x<=r)
				x+=d;
			cout<<x<<endl;
		}
	}
	return 0;
}