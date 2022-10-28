#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s;

bool check()
{
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='1'&&s[i+1]=='1')
		{
			return 0;
		}
	}
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	cin>>s;
	if(!check())
	{
		cout<<"No";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			s[i]='1';
			if(check())
			{
				cout<<"No";
				return 0;
			}
			s[i]='0';
		}
	}
	cout<<"Yes";
	return 0;
}