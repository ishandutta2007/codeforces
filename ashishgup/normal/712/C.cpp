#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int x, y;
int a[5];

int32_t main()
{
	IOS;
	cin>>x>>y;
	a[1]=y, a[2]=y, a[3]=y;
	for(int i=1;;i++)
	{
		a[1]=min(x, a[2]+a[3]-1);
		sort(a+1, a+4);
		if(a[1]==x)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}