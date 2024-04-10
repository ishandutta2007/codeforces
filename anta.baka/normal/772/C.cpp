#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> ban(200000, false);
vector<int> a[200000];
set<int> gcd;
vector<int> g[200000];
int dp[200000], to[200000];
vector<int> ans, ans1;

int GCD(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = GCD(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		ban[num] = true;
	}
	for(int i = 1; i < m; i++)
	{
		if(ban[i]) continue;
		int g = __gcd(i, m);
		a[g].push_back(i);
		gcd.insert(g);
	}
	for(auto it = gcd.begin(); it != gcd.end(); it++)
	{
		auto ti = it;
		for(ti++; ti != gcd.end(); ti++)
			if((*ti) % (*it) == 0) g[*it].push_back(*ti);
	}
	int v = -1;
	for(int i = m - 1; i > 0; i--)
	{
		dp[i] = a[i].size();
		to[i] = -1;
		for(int j : g[i])
			if(dp[i] < dp[j] + a[i].size())
			{
				dp[i] = dp[j] + a[i].size();
				to[i] = j;
			}
		if(v == -1 || dp[i] > dp[v]) v = i;
	}
	while(v != -1)
	{
		for(int num : a[v]) ans.push_back(num);
		v = to[v];
	}
	if(!ans.empty()) ans1.push_back(ans[0]);
	for(int i = 1; i < ans.size(); i++)
	{
		int a = ans[i - 1], b = m, c = ans[i];
		int x0, y0;
		int g = GCD(a, b, x0, y0);
		x0 = (1LL * x0 * (c / g)) % (b / g);
		if(x0 < 0) x0 += (b / g);
		ans1.push_back(x0);
	}
	if(!ban[0]) ans1.push_back(0);
	cout << ans1.size() << endl;
	for(int num : ans1) cout << num << ' ';
}