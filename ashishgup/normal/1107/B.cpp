#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int k, x;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>k>>x;
		int ans=9*(k-1) + x;
		cout<<ans<<endl;
	}
	return 0;
}