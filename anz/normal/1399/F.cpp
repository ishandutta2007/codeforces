#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pii seg[3001];
vector <int> x;

bool cmp(pii p1, pii p2)
{
	if (p1.first != p2.first) return p1.first < p2.first;
	return p1.second > p2.second;
}

int dp[3001][6001];
int solve(int idx, int r)
{
	if (idx == n) return 0;

	int& ret = dp[idx][r];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, solve(idx + 1, r));

	if (seg[idx].second <= r)
	{
		int nidx = lower_bound(seg + idx, seg + n, pii(seg[idx].second + 1, r), cmp) - seg;
		int res = solve(idx + 1, seg[idx].second)
			+ solve(nidx, r) + 1;

		ret = max(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		x.clear();

		for (int i = 0; i < n; i++) for (int j = 0; j < n * 2; j++) dp[i][j] = -1;

		for (int i = 0; i < n; i++)
		{
			int l, r; cin >> l >> r;
			seg[i] = { l,r };

			x.push_back(l);
			x.push_back(r);
		}

		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());

		for (int i = 0; i < n; i++)
		{
			int& l = seg[i].first;
			int& r = seg[i].second;

			l = lower_bound(x.begin(), x.end(), l) - x.begin();
			r = lower_bound(x.begin(), x.end(), r) - x.begin();
		}

		sort(seg, seg + n, cmp);
		cout << solve(0, n * 2 - 1) << '\n';
	}
}