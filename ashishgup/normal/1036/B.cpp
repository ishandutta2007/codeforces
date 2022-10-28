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
		int n, m, k;
		cin>>n>>m>>k;
		int minmoves=2*(abs(n-m)/2) + min(n, m) + (m%2 != n%2);
		if(k<minmoves)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int diff=k - minmoves;
		int ans=2*(abs(n-m)/2) + min(n, m);
		if(n%2==m%2)
		{
			if(diff%2==0)
				ans+=diff;
			else
				ans+=diff - 2;
		}
		else
			ans+=diff;
		cout<<ans<<endl;
	}
	return 0;
}