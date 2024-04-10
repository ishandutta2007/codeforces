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
		int n;
		cin>>n;
		int ans=n/7;
		if(n%7>0)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}