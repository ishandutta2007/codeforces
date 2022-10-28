#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int q;
	cin>>q;
	while(q--)
	{
		int n, a, b;
		cin>>n>>a>>b;
		int ans=0;
		if(n%2)
			ans+=a;
		int take=n/2;
		ans+=min(take*b, take*2*a);
		cout<<ans<<endl;
	}
	return 0;
}