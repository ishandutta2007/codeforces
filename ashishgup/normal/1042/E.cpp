#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;
const int MOD = 998244353;

int n, m, r, c;
int a[N][N], dp[N * N];
vector<pair<int, pair<int, int> > > v;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			v.push_back({a[i][j], {i, j}});
		}
	}
	cin >> r >> c;
	sort(v.begin(), v.end());
	int sumDp = 0, sumX = 0, sumX2 = 0, sumY = 0, sumY2 = 0;
	for(int i = 0; i < v.size(); i++)
	{
		int j = i;
		while(j + 1 < v.size() && v[i].first == v[j + 1].first)
			j++;
		if(i)
		{
			for(int k = i; k <= j; k++)
			{
				int x = v[k].second.first, y = v[k].second.second;
				dp[k] = sumDp;
				int xContrib = sumX2 + i * x * x - 2 * sumX * x;
				int yContrib = sumY2 + i * y * y - 2 * sumY * y;
				dp[k] += xContrib;
				dp[k] += yContrib;
				dp[k] %= MOD;
				dp[k] += MOD;
				dp[k] %= MOD;
				dp[k] *= modinv(i);
				dp[k] %= MOD;
			}
		}
		for(int k = i; k <= j; k++)
		{
			int x = v[k].second.first, y = v[k].second.second;
			sumX += x;
			sumX %= MOD;
			sumY += y;
			sumY %= MOD;
			sumX2 += x * x;
			sumX2 %= MOD;
			sumY2 += y * y;
			sumY2 %= MOD;
			sumDp += dp[k];
			sumDp %= MOD;
		}
		i = j;
	}
	for(int i = 0; i < v.size(); i++)
	{
		int x = v[i].second.first, y = v[i].second.second;
		if(x == r && y == c)
			cout << dp[i];
	}
	return 0;
}