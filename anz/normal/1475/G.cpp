#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[200001];
int cnt[200001];

int dp[200001];
int solve(int idx)
{
	int& ret = dp[idx];
	if (ret != -1) return ret;

	ret = cnt[idx];
	if (ret == 0) return 0;

	int res = 0;
	for (int nidx : graph[idx])
	{
		int tmp = solve(nidx);
		res = max(res, tmp);
	}

	ret += res;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i <= 200000; i++)
	{
		for (int j = i + i; j <= 200000; j += i) graph[i].push_back(j);
	}

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		memset(cnt, 0, sizeof cnt);
		memset(dp, -1, sizeof dp);

		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			cnt[a]++;
		}

		int ans = 0;
		for (int i = 1; i <= 200000; i++)
		{
			int res = solve(i);
			ans = max(ans, res);
		}

		//cout << "ANS:";
		cout << n - ans << '\n';
	}
}