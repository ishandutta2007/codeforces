#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n, m;
double ans=0, subt=0;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1,j=1;i+1<=n-1;i+=2,j++)
		subt+=j*2;
	if(n%2==0)
		subt+=n/2;
	for(int i=1;i<=m;i++)
	{
		int x, d;
		cin>>x>>d;
		ans+=x*n;
		if(d>=0)
			ans+=((double)d*(n-1)*n/2.0);
		else
			ans+=((double)d*subt);
	}
	ans/=n;
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}