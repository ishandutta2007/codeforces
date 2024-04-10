#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, ans;

int32_t main()
{
	IOS;
	cin>>n>>k;
	int ans=min(k-1, n) - (k/2 + 1) + 1;
	ans=max(ans, 0LL);
	cout<<ans;
	return 0;
}