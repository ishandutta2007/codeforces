#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
	IOS;
	int x, y, z;
	int a, b, c;
	cin>>x>>y>>z>>a>>b>>c;
	a-=x;
	if(a<0)
	{
		cout<<"NO";
		return 0;
	}
	int nonblack=a+b;
	if(nonblack<y)
	{
		cout<<"NO";
		return 0;
	}
	int rem=nonblack - y + c;
	if(rem<z)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES";
	return 0;
}