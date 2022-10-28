//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

int a, b, k;
int u[N], v[N];
set<int> g[N];


int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> k;
		int n = a + b;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= k; i++)
			cin >> u[i];
		for(int i = 1; i <= k; i++)
			cin >> v[i];
		for(int i = 1; i <= k; i++)
		{
			g[u[i]].insert(v[i] + a);
			g[v[i] + a].insert(u[i]);
		}
		int ans = 0;
		for(int i = 1; i <= k; i++)
		{
			int l = u[i], r = v[i] + a;
			int rem = (k - 1) - g[l].size() - g[r].size() + 2;
			ans += rem;
		}
		cout << ans / 2 << endl;
	}
	return 0;
}