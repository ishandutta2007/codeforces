#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='1')
			{
				cout<<abs(i-3) + abs(j-3);
				return 0;
			}
		}
	}
	return 0;
}