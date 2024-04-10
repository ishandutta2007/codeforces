#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, k;
	cin>>n>>k;
	int ans=(n/k + 1)*k;
	cout<<ans;
	return 0;
}