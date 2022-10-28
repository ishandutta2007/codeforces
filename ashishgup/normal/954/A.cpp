#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string s;
int check()
{
	int n=s.size();
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='R'&&s[i+1]=='U')
			return 1;
		if(s[i]=='U'&&s[i+1]=='R')
			return 1;
	}
	return 0;
}

void shorten()
{
	string ans="";
	int n=s.size();
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='R'&&s[i+1]=='U')
		{
			ans+='D';
			for(int j=i+2;j<n;j++)
			{
				ans+=s[j];
			}
			break;
		}
		if(s[i]=='U'&&s[i+1]=='R')
		{
			ans+='D';
			for(int j=i+2;j<n;j++)
			{
				ans+=s[j];
			}
			break;
		}
		ans+=s[i];
	}
	s=ans;
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	cin>>s;
	while(check())
	{
		shorten();
	}
	cout<<s.size();
	return 0;
}