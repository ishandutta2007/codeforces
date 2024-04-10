#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int steps_gcd(int a, int b)
{
	if(a==0)
		return 0;
	return b/a + steps_gcd(b%a, a);
}

int32_t main()
{
	IOS;
	int a, b;
	cin>>a>>b;
	cout<<steps_gcd(a, b);
	return 0;
}