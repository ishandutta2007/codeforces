#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int solve(int n)
{
	if(n<=1)
		return 0;
	return n/2 + 2 * solve(n/2 + n%2);
}

int32_t main()
{
	IOS;
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}