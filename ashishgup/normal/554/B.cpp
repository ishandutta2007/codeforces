#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, ans=0;
map<string, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		m[s]++;
	}	
	for(auto &it:m)
		ans=max(ans, it.second);
	cout<<ans;
	return 0;
}