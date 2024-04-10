#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int x[5], y[5];
set<int> xs, ys;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		xs.insert(x[i]);
		ys.insert(y[i]);
	}
	if(xs.size()<2 || ys.size()<2)
		cout<<"-1";
	else
	{
		int diffx=(*(--xs.end()))-*(xs.begin());
		int diffy=(*(--ys.end()))-*(ys.begin());
		cout<<diffx*diffy;
	}
	return 0;
}