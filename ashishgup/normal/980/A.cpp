#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin>>s;
	int ct1=0, ct2=0;
	for(auto it:s)
	{
		if(it=='o')
			ct1++;
		else
			ct2++;
	}
	if(ct1<=1)
	{
		cout<<"YES";
		return 0;
	}
	if(ct2%ct1==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}