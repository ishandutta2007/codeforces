#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, k;
int a[N], pref[N];
double ans=0;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+k-1;j<=n;j++)
		{
			double cur=((double)pref[j]-pref[i-1])/(j-i+1);
			ans=max(ans, cur);
		}
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}