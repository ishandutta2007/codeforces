#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
string s, ans="";

int32_t main()
{
	IOS;
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.')
			ans+='0';
		else if(i+1<n && s[i+1]=='.')
			ans+='1', i++;
		else
			ans+='2', i++;
	}
	cout<<ans;
	return 0;
}