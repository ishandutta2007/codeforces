#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	if(a>b)
		swap(a, b);
	int ans=0;
	int ct=1;
	for(;a<b;a++, b--)
	{
		ans+=2*ct;
		ct++;
	}
	if(a>b)
	{
		ans-=(ct-1);
	}
	cout<<ans;
	return 0;
}