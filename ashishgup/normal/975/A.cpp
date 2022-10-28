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
	set<string> ans;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		map<char, int> m;
		for(auto it:s)
			m[it]++;
		string cur="";
		for(auto it:m)
			cur+=it.first;
		ans.insert(cur);
	}
	cout<<ans.size();
	return 0;
}