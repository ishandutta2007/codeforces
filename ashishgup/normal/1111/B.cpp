#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n, k, m, sum=0;
int a[N];
double ans=0;

int32_t main()
{
	IOS;
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1, a+n+1);
	double rem=sum;
	for(int i=0;i<=min(n-1, m);i++)
	{
		rem-=a[i];
		double extra=m-i;
		double value=rem + min(extra, 1.0l*k*(n-i));
		ans=max(ans, value/(n-i));
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}