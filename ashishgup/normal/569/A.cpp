#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int t, s, q;
	cin>>t>>s>>q;
	int ans=0;
	while(s<t)
	{
		s*=q;
		ans++;
	}
	cout<<ans;
	return 0;
}