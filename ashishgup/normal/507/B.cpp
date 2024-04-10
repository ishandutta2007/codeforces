#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

int distance(int x1, int y1, int x2, int y2)
{
	return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
}

int32_t main()
{
	IOS;
	int r, x, y, x2, y2;
	cin>>r>>x>>y>>x2>>y2;
	double dist=distance(x, y, x2, y2);
	dist=sqrtl(dist);
	dist/=(2*r);
	int ans=ceill(dist);
	cout<<ans;
	return 0;
}