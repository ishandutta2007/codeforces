#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int cur = 1e18;
	for(int i=n;i>=1;i--)
	{
		cur = min(cur - 1, a[i]);
		cur = max(0LL, cur);
		ans += cur;
	}
	cout<<ans;
	return 0;
}