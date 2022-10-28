#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, m;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		auto it=lower_bound(a+1, a+n+1, b[i]);
		int ans=it-a;
		cout<<ans<<" "<<b[i]-a[ans-1]<<endl;
	}
	return 0;
}