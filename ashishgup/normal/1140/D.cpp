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
	n--;
	int ans = n * (n + 1) * (n + 2) / 3 - 2;
	cout<<ans<<endl;
	return 0;
}