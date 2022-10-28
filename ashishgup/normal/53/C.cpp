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
	for(int i=1, j=n; i<=j; i++, j--)
	{
		cout<<i<<" ";
		if(i!=j)
			cout<<j<<" ";
	}
	return 0;
}