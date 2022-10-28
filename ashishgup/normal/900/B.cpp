#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b, c;

int32_t main()
{
	IOS;
	cin>>a>>b>>c;
	int cur=a;
	for(int i=1;i<=b+1;i++)
	{
		cur*=10;
		int dig=cur/b;
		cur%=b;
		if(dig==c)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}