#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

double x1, y1, r1, x2, y2, r2, r, ans;

int32_t main()
{
	IOS;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	r=sqrtl(pow(x2-x1, 2) + pow(y2-y1, 2));
	if(r>=r1+r2)
		ans=r-r1-r2;
	else if(r1>r+r2)
		ans=r1-r-r2;
	else if(r2>r+r1)
		ans=r2-r-r1;
	else
		ans=0;
	ans/=2;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}