#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

int32_t main()
{
	IOS;
	int m, n;
	cin>>m>>n;
	double ans=0;
	for(int i=1;i<=m;i++)
	{
		double cur=pow((double)i/m, n) - pow(((double)i-1)/m, n);
		cur*=i;
		ans+=cur;
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}