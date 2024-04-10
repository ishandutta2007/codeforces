#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int cur=0, ans=0, stmin=0;
string s;

int32_t main()
{
	IOS;
	cin>>s;
	for(auto &it:s)
	{
		cur+=(it=='+');
		cur-=(it=='-');
		stmin=min(stmin, cur);
		ans=max(ans, cur);
	}
	cout<<ans-stmin;
	return 0;
}