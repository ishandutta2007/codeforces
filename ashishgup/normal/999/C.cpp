#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
string s;
map<char, int> m;

int32_t main()
{
	IOS; 
	cin>>n>>k>>s;
	for(auto it:s)
		m[it]++;
	for(auto &it:m)
	{
		int del=min(k, it.second);
		k-=del;
		it.second-=del;
	}
	string ans="";
	for(int i=n-1;i>=0;i--)
	{
		if(m[s[i]]>0)
		{
			ans+=s[i];
			m[s[i]]--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout<<ans;
	return 0;   
}