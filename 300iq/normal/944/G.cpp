#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 7;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
	a += b;
	if (a >= M) a -= M;
	return a;
}

inline int mul(int a, int b)
{
	return (a * (ll) b) % M;
}

inline int bin(int a, int n)
{
	int res = 1;
	while (n)
	{
		if (n % 2 == 0)
		{
			a = mul(a, a);
			n /= 2;
		}
		else
		{
			res = mul(res, a);
			n--;
		}
	}
	return res;
}

int lf[N][3];
int cnt[N][3];
int dp[N][3];
int s[3];
int cur[3];
int val[N][3];

int n;

void rec(int l, int r)
{
	if (r - l == 1)
	{
		return;
	}
	else
	{
		int m = (l + r) / 2;
		rec(l, m);
		for (int i = 0; i < 3; i++)
		{
			s[i] = 0;
			cur[i] = 1;
		}
		for (int i = m - 1; i >= l; i--)
		{
			for (int t = 0; t < 3; t++)
			{
				val[i][t] = 0;
				if (i != 0)
				{
					for (int p = 0; p < 3; p++)
					{
						if (t != p)
						{
							val[i][t] = add(val[i][t], mul(cur[t], dp[i][p]));
						}
					}
				}
				else
				{
					val[i][t] = cur[t];
				}
			}
			for (int t = 0; t < 3; t++)
			{
				if (i + 1 < m)
				{
					val[i][t] = add(val[i][t], val[i + 1][t]);
				}
			}
			for (int t = 0; t < 3; t++)
			{
				cur[t] = mul(cur[t], cnt[i][t]);
			}
		}
		for (int t = 0; t < 3; t++)
		{
			cur[t] = 1;
		}
		for (int i = m; i < r; i++)
		{
			for (int t = 0; t < 3; t++)
			{
				cur[t] = mul(cur[t], cnt[i][t]);
			}
			for (int t = 0; t < 3; t++)
			{
				int go = max(l, (t == 2 ? 0 : lf[i][t ^ 1]));
				if (go >= m)
				{
					continue;
				}
				dp[i][t] = add(dp[i][t], mul(val[go][t], cur[t]));
			}
		}
		rec(m, r);
	}
}

vector <int> x;

void add_segm(int l, int r)
{
	x.push_back(r);
	x.push_back(r + 1);
	x.push_back(l);
	x.push_back(l + 1);
}

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, n, m;
	cin >> k >> n >> m;
	vector <pair <int, int> > a, b;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		add_segm(l, r);
		a.push_back({l, r});
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		add_segm(l, r);
		b.push_back({l, r});
	}
	x.push_back(0);
	x.push_back(1);
	x.push_back(k + 1);
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	for (int i = 0; i < (int) x.size() - 1; i++)
	{
		if (i == 0)
		{
		}
		else
		{
			int l = x[i], r = x[i + 1] - 1;
			int len = r - l + 1;
			cnt[i][0] = cnt[i][1] = 1;
			if (len == 1)
			{
				cnt[i][2] = 0;
			}
			else
			{
				cnt[i][2] = add(bin(2, len), M - 2);
			}
		}
	}
	int sz = (int) x.size() - 1;
	for (auto c : a)
	{
		int ind = lower_bound(x.begin(), x.end(), c.first) - x.begin();
		int jnd = lower_bound(x.begin(), x.end(), c.second) - x.begin();
		lf[jnd][0] = max(lf[jnd][0], ind);
	}
	for (auto c : b)
	{
		int ind = lower_bound(x.begin(), x.end(), c.first) - x.begin();
		int jnd = lower_bound(x.begin(), x.end(), c.second) - x.begin();
		lf[jnd][1] = max(lf[jnd][1], ind);
	}
	for (int i = 1; i < sz; i++)
	{
		for (int t = 0; t < 2; t++)
		{
			lf[i][t] = max(lf[i - 1][t], lf[i][t]);
		}
	}
	rec(0, sz);
	int ans = 0;
	for (int t = 0; t < 3; t++)
	{
		ans = add(ans, dp[sz - 1][t]);
	}
	cout << ans << '\n';
}