#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int s[100001];

int dp[100001];
int solve(int i)
{
	if (dp[i] != -1) return dp[i];
	dp[i] = 0;
	for (int j = 2; i * j <= n; j++)
	{
		if(s[i] < s[i*j])
			dp[i] = max(dp[i], solve(i * j));
	}

	return ++dp[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			dp[i] = -1;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, solve(i));

		cout << ans << '\n';
	}
}