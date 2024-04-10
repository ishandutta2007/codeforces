#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

double m, r, ans=0;

double val(int n)
{
	double ans=0;
	ans=(2*r + sqrtl(2)*r)*n + (n*(n-1)*r) - (2*r - sqrtl(2)*r)*(max(0LL, n-1));
	return ans;
}

int32_t main()
{
	IOS;
	cin>>m>>r;
	for(int i=1;i<=m;i++)
	{
		int left=i-1;
		int right=(m-i);
		ans+=2*r;
		ans+=val(left);
		ans+=val(right);
	}
	ans/=(m*m);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}