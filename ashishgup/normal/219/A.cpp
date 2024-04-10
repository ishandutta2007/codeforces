#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;
string s;
map<char, int> m;

int32_t main()
{
	IOS;
	cin>>k>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		m[s[i]]++;
	string ans="";
	for(auto &it:m)
	{
		if(it.second%k)
		{
			cout<<"-1";
			return 0;
		}
		for(int j=1;j<=it.second/k;j++)
			ans+=it.first;
	}
	string finans="";
	for(int i=1;i<=k;i++)
		finans+=ans;
	cout<<finans;
	return 0;
}