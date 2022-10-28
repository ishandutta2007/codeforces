#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		sort(s.begin(), s.end());
		string t=s;
		reverse(t.begin(), t.end());
		if(s==t)
			cout<<"-1"<<endl;
		else
			cout<<s<<endl;
	}
	return 0;
}