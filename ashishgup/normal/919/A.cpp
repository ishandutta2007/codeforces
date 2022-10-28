#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e6+5;

long double a[N], b[N];
long double min1=1e9;

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		min1=min(min1, (long double)a[i]/b[i]);
	}
	long double ans=min1*m;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}