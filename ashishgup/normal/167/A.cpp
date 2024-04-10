#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e6+5;

int n, a, d;
double ans=0;
double t[N], v[N];

int32_t main()
{
	IOS;
	cin>>n>>a>>d;
	for(int i=1;i<=n;i++)
	{
		double curd=d;
		cin>>t[i]>>v[i];
		double dist=v[i]*v[i]/(2*a);
		dist=min(dist, curd);
		double cur=2*dist/a;
		cur=sqrtl(cur);
		curd-=dist;
		cur+=curd/v[i];
		cur+=t[i];
		ans=max(ans, cur);
		cout<<fixed<<setprecision(12)<<ans<<endl;
	}
	return 0;
}