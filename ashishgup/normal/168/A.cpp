#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, x, y;

int32_t main()
{
	IOS;
	cin>>n>>x>>y;
	for(int ans=0;;ans++)
	{
		int lhs=100*(x+ans);
		int rhs=n*y;
		if(lhs>=rhs)
		{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}