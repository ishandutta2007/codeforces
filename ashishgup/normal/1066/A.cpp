#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		int L, v, l, r;
		cin>>L>>v>>l>>r;
		int tot=L/v;
		int sub=(r/v - (l-1)/v);
		int ans=tot-sub;
		cout<<ans<<endl;
	}
	return 0;
}