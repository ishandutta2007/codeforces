#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int f[N];

void inc(int x, int y)
{
	for (; x < N; x = (x | (x + 1)))
	{
		f[x] = max(f[x], y);
	}
}

int get(int x)
{
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
	{
		ans = max(ans, f[x]);
	}
	return ans;
}

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	vector <int> a(n + 1);
	vector <int> dp(n + 7);
	vector <int> rdp(n + 7);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		a[l]++;
		a[r + 1]--;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
	}
	multiset <int> s;
	for (int i = 0; i < n; i++)
	{
		auto it = s.upper_bound(a[i]);
		if (it != s.end())
		{
			s.erase(it);
		}
		s.insert(a[i]);
		dp[i] = (int) s.size();
	}
	s.clear();
	for (int i = n - 1; i >= 0; i--)
	{
		auto it = s.upper_bound(a[i]);
		if (it != s.end())
		{
			s.erase(it);
		}
		s.insert(a[i]);
		rdp[i] = (int) s.size();
	}
	int ans = rdp[0];
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp[i] + rdp[i + 1]);
	}
	cout << ans << '\n';
}