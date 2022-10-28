#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	int n;
	string s;
	cin>>n>>s;
	map<string, int> m;
	int f=0;
	for(int i=0;i+1<n;i++)
	{
		string cur="";
		cur+=s[i];
		cur+=s[i+1];
		m[cur]++;
		f=max(f, m[cur]);
	}
	for(auto it:m)
	{
		if(it.second==f)
		{
			cout<<it.first;
			return 0;
		}
	}
	return 0;
}