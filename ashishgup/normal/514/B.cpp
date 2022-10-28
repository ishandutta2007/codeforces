#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, x0, y0;
int x[N], y[N];
set<pair<int, int> > s;

int32_t main()
{
	IOS;
	cin>>n>>x0>>y0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		int ydiff=(y[i]-y0);
		int xdiff=(x[i]-x0);
		int store=__gcd(abs(ydiff), abs(xdiff));
		xdiff/=store;
		ydiff/=store;
		if(xdiff==0)
			ydiff=1;
		if(ydiff<0)
			xdiff*=-1, ydiff*=-1;
		if(ydiff==0)
			xdiff=0;
		s.insert({xdiff, ydiff});
	}	
	cout<<s.size();
	return 0;
}