#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	set<char> s;
	for(int i=1;i<=2;i++)
	{
		char ch;
		cin>>ch;
		s.insert(ch);
	}
	for(int i=1;i<=10;i++)
	{
		char ch;
		cin>>ch;
		if(s.find(ch)!=s.end())
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
	return 0;
}