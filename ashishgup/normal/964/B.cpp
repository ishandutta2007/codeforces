#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, a, b, c, T, t;
	cin>>n>>a>>b>>c>>T;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans+=a;
		if(c>=b)
			ans+=(T-t)*(c-b);
	}
	cout<<ans;
	return 0;
}