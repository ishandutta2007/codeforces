#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, a, b;

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	a--;
	b%=n;
	int ans=(a+b+n)%n;
	cout<<ans+1;
	return 0;
}