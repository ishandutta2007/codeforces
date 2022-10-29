#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s, ans="";

int32_t main()
{
	IOS;
	cin>>s;
	for(auto it:s)
		if(it=='1')
			ans+=it;
	for(auto it:s)
		if(it!='1')
			ans+=it;
	bool check=0;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]=='2')
		{
			check=1;
			sort(ans.begin(), ans.begin()+i);
			break;
		}
	}
	if(!check)
		sort(ans.begin(), ans.end());
	cout<<ans;
	return 0;
}