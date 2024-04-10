#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 82;

int n;
int a[N], f[N], init[2][N];
int cache[N][N][6400];
int cache2[N][N][N];

int get(int idx, int k, int cur)
{
	if(k == 0)
		return 0;
	int &ans = cache2[idx][k][cur];
	if(ans != -1)
		return ans;
	ans = abs(idx - init[0][cur]) + get(idx + 1, k - 1, cur + 1);
	return ans;
}

int dp(int idx, int sum, int k)
{
	if(k < 0)
		return -2e18;
	if(idx > f[1])
		return -2e18;
	int curidx = idx + sum + 1;
	if(curidx > n)
		return 0;
	int &ans = cache[idx][sum][k];
	if(ans != -1)
		return ans;
	ans = -2e18;
	ans = max(ans, dp(idx + 1, sum, k - abs(curidx - init[1][idx + 1])));
	int rem = f[0] - sum;
	int lo = 1;
	if(idx == f[1])
		lo = rem;
	for(int i = lo; i <= rem; i++)
	{
		// int subtract = 0;
		// for(int j = curidx; j <= curidx + i - 1; j++)
		// 	subtract += abs(j - init[0][sum + j + 1 - curidx]);
		int subtract = get(curidx, i, sum + 1);
		int nidx = idx;
		if(idx + 1 <= f[1])
		{
			nidx++;
			subtract += abs(curidx + i - init[1][idx + 1]);
		}
		ans = max(ans, i * sum + dp(nidx, sum + i, k - subtract));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
		init[a[i]][f[a[i]]] = i;
	}
	if(!f[0] || !f[1])
	{
		for(int k = 0; k <= n * (n - 1) / 2; k++)
			cout << 0 << " ";
		cout << endl;
		return 0;
	}
	for(int k = 0; k <= n * (n - 1) / 2; k++)
		cout << dp(0, 0, 2 * k) << " ";
	return 0;
}