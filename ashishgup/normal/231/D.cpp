#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int x, y, z;
	cin>>x>>y>>z;
	int x1, y1, z1;
	cin>>x1>>y1>>z1;
	int a1, a2, a3, a4, a5, a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	int ans=0;
	if(x>x1)
		ans+=a6;
	else if(x<0)
		ans+=a5;
	if(y>y1)
		ans+=a2;
	else if(y<0)
		ans+=a1;
	if(z>z1)
		ans+=a4;
	else if(z<0)
		ans+=a3;
	cout<<ans;
	return 0;
}