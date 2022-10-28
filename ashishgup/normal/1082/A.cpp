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
		int n, x, y, d;
		cin>>n>>x>>y>>d;
		int diff=abs(x-y);
		if(diff%d==0)
			cout<<diff/d<<endl;
		else
		{
			int ans=1e15;
			if((y-1)%d==0)
			{
				int cur=(x-1+d-1)/d;
				cur+=(y-1)/d;
				ans=min(ans, cur);
			}
			if((n-y)%d==0)
			{
				int cur=(n-x+d-1)/d;
				cur+=(n-y)/d;
				ans=min(ans, cur);
			}
			if(ans>1e10)
				ans=-1;
			cout<<ans<<endl;
		}
	}
	return 0;
}