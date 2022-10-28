#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n;
double angle[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double x,y;
		cin>>x>>y;
		angle[i]=atan2l(y,x)*(180/acosl(-1));
	}
	double ans=500;
	sort(angle+1, angle+n+1);
	for(int i=1;i<n;i++)
	{
		ans=min(ans,360-(angle[i+1]-angle[i]));
	}
	ans=min(ans,angle[n]-angle[1]);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}