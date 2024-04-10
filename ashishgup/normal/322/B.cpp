#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int r, g, b;
	cin>>r>>g>>b;
	int min1=min({r, g, b});
	int finans=0;
	for(int i=0;i<=min(min1, 3LL);i++)
	{
		int ans=0;
		ans+=(r-i)/3;
		ans+=(g-i)/3;
		ans+=(b-i)/3;
		ans+=i;
		finans=max(ans, finans);
	}
	cout<<finans;
	return 0;
}