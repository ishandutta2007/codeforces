#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		ans+=(s[1]=='+');
		ans-=(s[1]=='-');
	}
	cout<<ans;
	return 0;
}