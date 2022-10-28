#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k, ans = 0;
int a[N];
int rem[5][N];
set<int> vis;

int32_t main()
{
	IOS;
	cin >> n >> k;
	int ans = 3 * n - 2;
	for(int i = 1; i <= k; i++)
		cin >> a[i];
	for(int i = 1; i <= k; i++)
	{
		vis.insert(a[i]);
		rem[1][a[i]]++;
		if(vis.find(a[i] - 1) != vis.end())
			rem[2][a[i]]++;
		if(vis.find(a[i] + 1) != vis.end())
			rem[3][a[i]]++;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 3; j++)
			ans -= min(1LL, rem[j][i]);
	cout << ans;
	return 0;
}