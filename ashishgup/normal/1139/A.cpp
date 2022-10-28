#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, ans = 0;
string s;

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if((s[i]-'0')%2==0)
			ans += (i + 1);
	cout<<ans;
	return 0;
}