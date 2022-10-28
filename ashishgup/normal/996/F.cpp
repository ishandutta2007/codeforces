#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

const int N=(1LL<<19);

int n, r, sum=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>r;
	n=(1LL<<n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	double ans=(double)sum/n;
	cout<<fixed<<setprecision(12)<<ans<<endl;
	for(int i=1;i<=r;i++)
	{
		int idx, val;
		cin>>idx>>val;
		idx++;
		sum-=a[idx];
		a[idx]=val;
		sum+=a[idx];
		ans=(double)sum/n;
		cout<<fixed<<setprecision(12)<<ans<<endl;
	}
}