#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int a, b, k;
		cin>>a>>b>>k;
		int ans=k/2 * (a-b);
		if(k%2)
			ans+=a;
		cout<<ans<<endl;
	}
	return 0;
}