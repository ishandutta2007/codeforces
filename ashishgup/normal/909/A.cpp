#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
	IOS;
	string a, b;
	cin>>a>>b;
	string ans="zzzzzzzzzzzz";
	int as=a.size();
	int bs=b.size();
	for(int i=1;i<=as;i++)
	{
		for(int j=1;j<=bs;j++)
		{
			string pref1=a.substr(0, i);
			string pref2=b.substr(0, j);
			string cur=pref1+pref2;
			if(cur<ans)
				ans=cur;
		}
	}
	cout<<ans;
	return 0;
}