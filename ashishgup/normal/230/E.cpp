#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, m;
int deg[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		deg[u]++, deg[v]++;
	}
	int ans = n * (n - 1) * (n - 2) / 6;
	int rem = 0;
	for(int i = 1; i <= n; i++)
		rem += deg[i] * (n - 1 - deg[i]);
	rem /= 2;
	ans -= rem;
	cout << ans;
	return 0;
}