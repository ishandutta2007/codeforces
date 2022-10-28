#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD=1e9+7;

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int n=s.size();
	int store=0;
	int count=0;
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='b')
			count++;
		else
		{
			ans+=count+store;
			ans%=MOD;
			store=(store+count)*2;
			store=store%MOD;
			count=0;
		}
	}
	cout<<ans;
	return 0;
}