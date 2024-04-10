#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;

int32_t main()
{
	IOS;
	cin>>n>>k;
	int ans=n-(k-2*n);
	ans=max(0LL, ans);
	cout<<ans;
	return 0;
}