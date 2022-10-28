#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 81;
const int K = 11;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int n, k;
int cost[N][N];
int col[N];
int cache[N][K];

int dp(int u, int k)
{
	if(k == 0)
	{
		if(u == 1)
			return 0;
		return 1e12;
	}
	int &ans = cache[u][k];
	if(ans != -1)
		return ans;
	ans = 1e12;
	for(int i = 1; i <= n; i++)
	{
		if(u != i && col[i] ^ col[u])
			ans = min(ans, cost[u][i] + dp(i, k - 1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> cost[i][j];
	int answer = 1e12;
	while((double)clock() / CLOCKS_PER_SEC < 2.6)
	{
		memset(cache, -1, sizeof(cache));
		for(int i = 1; i <= n; i++)
			col[i] = getRand(0, 1);
		int cur = dp(1, k);
		answer = min(answer, cur);
	}
	cout << answer;
	return 0;
}