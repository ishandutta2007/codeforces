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
	int ans=(n+1)/2;
	if(n%2)
		ans*=-1;
	cout<<ans;
	return 0;
}