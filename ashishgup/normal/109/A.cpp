#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
int32_t main()
{
	IOS;
	int n;
	cin>>n;
	for(int four=0;four*4<=n;four++)
	{
		int rem=n-four*4;
		if(rem%7==0)
		{
			for(int j=1;j<=four;j++)
				cout<<"4";
			for(int j=1;j<=rem/7;j++)
				cout<<"7";
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}