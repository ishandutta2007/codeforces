#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

string s, t;
int n, m, ans=1e5;

int32_t main()
{
	IOS;
	cin>>s>>t;
	m=t.size();
	string temp="";
	for(int i=0;i<m;i++)
		temp+='#';
	s=temp+s+temp;
	n=s.size();
	for(int i=0;i+m<=n;i++)
	{
		int cur=0;
		for(int j=0;j<m;j++)
		{
			cur+=(s[i+j]!=t[j]);
		}
		ans=min(ans, cur);
	}
	cout<<ans;
	return 0;
}