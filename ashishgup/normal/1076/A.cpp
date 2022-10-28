#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n;
string s, ans="";

int32_t main()
{
	IOS;
	cin>>n>>s;
	for(int i=0;i+1<n;i++)
	{
		if(s[i]>s[i+1])
		{
			for(int j=i+1;j<n;j++)
				ans+=s[j];
			break;
		}
		else
			ans+=s[i];
	}
	cout<<ans;
	return 0;
}