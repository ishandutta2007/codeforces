#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> a, b;
int dp[5001][5001];

int solve(int ai, int bi)
{
	if (ai == a.size()) return 0;

	int& ret = dp[ai][bi];
	if (ret != -1) return ret;

	ret = solve(ai + 1, bi + 1) + abs(a[ai] - b[bi]);
	if (a.size() - ai < b.size() - bi)
	{
		int res = solve(ai, bi + 1);
		ret = min(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if (x) a.push_back(i);
		else b.push_back(i);
	}

	memset(dp, -1, sizeof dp);

	int ans = solve(0, 0);
	cout << ans;
}