#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ett[10001];
vector <int> p;

int n, k;
int a[200001];

int rmx[21][200001];
int dp[21][200001];
int solve(int idx, int rk)
{
	if (idx >= n) return 0;

	int& ret = dp[rk][idx];
	if (ret != -1) return ret;
	ret = 1e9;

	for (int i = 0; i <= rk; i++)
	{
		int res = 1 + solve(rmx[i][idx], rk - i);
		ret = min(ret, res);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= 10000; i++)
	{
		if (ett[i] == 0)
		{
			p.push_back(i);
			for (int j = i + i; j <= 10000; j += i) ett[j] = 1;
		}
	}

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;

		for (int i = 0; i <= k; i++) for (int j = 0; j < n; j++)
			dp[i][j] = -1;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];

			int c = a[i];
			for (int j = 0; j < p.size() && p[j] * p[j] <= a[i]; j++)
			{
				while (c % (p[j] * p[j]) == 0) c /= p[j] * p[j];
			}

			a[i] = c;
		}

		set <int> mp;
		set <pii> midx; // {num, idx}
		set <int> st;

		int rptr = 0;
		for (int i = 0; i < n; i++)
		{
			while (rptr < n && midx.size() <= k)
			{
				if (st.find(a[rptr]) != st.end())
				{
					midx.insert({ a[rptr], rptr });
					mp.insert(rptr);
				}
				else st.insert(a[rptr]);

				rptr++;
			}

			auto it = mp.begin();
			for (int j = 0; j <= k; j++)
			{
				if (it == mp.end()) rmx[j][i] = n;
				else
				{
					rmx[j][i] = *it;
					it++;
				}
			}

			auto jt = midx.lower_bound({ a[i], 0 });
			if (jt != midx.end() && jt->first == a[i])
			{
				int idx = jt->second;
				mp.erase(idx);
				midx.erase(jt);
			}
			else st.erase(a[i]);
		}

		int res = solve(0, k);
		cout << res << '\n';
	}
}