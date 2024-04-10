#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int h1, h2, a, b;

int32_t main()
{
	IOS;
	cin>>h1>>h2>>a>>b;
	int diff=h2-h1;
	int firstday=8*a;
	if(firstday>=diff)
	{
		cout<<"0";
		return 0;
	}
	diff-=firstday;
	int gain=12*(a-b);
	if(gain<=0)
	{
		cout<<"-1";
		return 0;
	}
	int days=(diff+gain-1)/gain;
	cout<<days;
	return 0;
}