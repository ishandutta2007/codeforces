//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 5005;
const int MOD = 1e9 + 7;

int n, k, q, sum = 0;
int a[N], tot[N];
int cache[N][N];

int dp(int idx, int x) //n * n => n^2 dp
{
	if(idx < 1 || idx > n)
		return 0;
	if(x == k)
		return 1;
	int &ans = cache[idx][x];
	if(ans != -1)
		return ans;
	ans = (dp(idx + 1, x + 1) + dp(idx - 1, x + 1)) % MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> k >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			tot[i] += (1LL * dp(i, j) * dp(i, k - j)) % MOD;
			tot[i] %= MOD;
		}
		sum += (1LL * tot[i] * a[i]) % MOD;
		sum %= MOD;
	}
	while(q--)
	{
 		int idx, val;
		cin >> idx >> val;
		sum -= (1LL * tot[idx] * a[idx]) % MOD;
		sum %= MOD;
		sum += MOD;
		sum %= MOD;
		a[idx] = val;
		sum += (1LL * tot[idx] * a[idx]) % MOD;
		sum %= MOD;
		cout << sum << endl;
	}
	return 0;
}

// (i, x) => number of ways of reaching i at xth index => left with x - 1 moves, and I go right with k - x moves