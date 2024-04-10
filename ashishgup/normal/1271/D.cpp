#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n, m, k;
int a[N], b[N], c[N];
int last[N];
int cache[N][N];
vector<int> g[N];

int dp(int i, int have)
{	
	if(have < a[i])
		return -1e9;
	if(i > n)
		return 0;
	int &ans = cache[i][have];
	if(ans != -1)
		return ans;
	ans = dp(i + 1, have + b[i]);
	int x = have + b[i];
	int sum = 0;
	for(int j = 0; j < g[i].size(); j++)
	{
		sum += g[i][j];
		if(x >= j + 1)
			ans = max(ans, sum + dp(i + 1, x - (j + 1)));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		last[i] = i;
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		last[v] = max(last[v], u);
	}
	for(int i = 1; i <= n; i++)
		g[last[i]].push_back(c[i]);
	for(int i = 1; i <= n; i++)
		sort(g[i].rbegin(), g[i].rend());
	int ans = dp(1, k);
	if(ans < 0)
		ans = -1;
	cout << ans;
	return 0;
}