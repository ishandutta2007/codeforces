#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	string ans="";
	for(int i=0;i<s.size();i++)
	{
		if(i+2<s.size() && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
		{
			i+=2;
			if(ans.size() && ans.back()!=' ')
				ans+=' ';
			continue;
		}
		ans+=s[i];
	}
	cout<<ans;
	return 0;
}