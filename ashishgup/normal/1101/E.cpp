#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e5+5;

int n, mn=1, mx=1;

int32_t main()
{
	IOS;
	cin>>n;
	while(n--)
	{
		char ch;
		cin>>ch;
		if(ch=='+')
		{
			int x, y;
			cin>>x>>y;
			mn=max(mn, min(x, y));
			mx=max(mx, max(x, y));
		}
		else
		{	
			int h, w;
			cin>>h>>w;
			if(h>w)
				swap(h, w);
			if(mn<=h && mx<=w)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}