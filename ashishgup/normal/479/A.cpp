#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int a, b, c;
	cin>>a>>b>>c;
	int ans=max({a+b+c, a*(b+c), (a+b)*c, a*b*c});
	cout<<ans;
}