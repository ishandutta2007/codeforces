#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
string s;

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	map<char, int> m;
	for(int i=0;i<n;i++)
	{
		m[s[i]]++;
	}
	int ct=0;
	for(auto it:m)
	{
		if(it.second>=2)
		{
			ct++;
		}
	}
	if(m.size()>4)
	{
		cout<<"No";
		return 0;
	}
	if(m.size()==4)
	{
		cout<<"Yes";
		return 0;
	}
	if(m.size()==3 && ct>=1)
	{
		cout<<"Yes";
		return 0;
	}
	if(m.size()==3)
	{
		cout<<"No";
		return 0;
	}
	if(m.size()==2 && ct>=2)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}