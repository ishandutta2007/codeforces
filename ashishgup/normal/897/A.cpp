#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
	IOS;
	int n, m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=m;i++)
	{
		string ans="";
		int l, r;
		char c1, c2;
		cin>>l>>r>>c1>>c2;
		for(int j=0;j<l-1;j++)
		{
			ans+=s[j];
		}
		for(int j=l-1;j<=r-1;j++)
		{
			if(s[j]==c1)
				ans+=c2;
			else
				ans+=s[j];
		}
		for(int j=r;j<n;j++)
		{
			ans+=s[j];
		}
		s=ans;
	}
	cout<<s;
	return 0;
}