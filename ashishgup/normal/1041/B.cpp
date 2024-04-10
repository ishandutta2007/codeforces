#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;  

int a, b, x, y;

int32_t main()
{
	IOS;
	cin>>a>>b>>x>>y;
	int store=__gcd(x, y);
	x/=store;
	y/=store;
	int minw=x, minh=y;
	int num=a/minw;
	num=min(num, b/minh);
	cout<<num;
	return 0;
}