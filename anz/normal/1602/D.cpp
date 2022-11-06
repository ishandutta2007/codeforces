#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 300001;
const int INF = 1e9;

int n;
int a[N];
int b[N];

int dp[N];
int par[N];
int back[N];
int cache[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(dp, dp + N, INF);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	int last = n - 1;
	dp[n] = 0, par[n] = n;
	cache[n] = 1;

	queue <int> q; q.push(n);
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		while (last >= v - a[v])
		{
			dp[last] = dp[par[v]] + 1;
			back[last] = par[v];

			int nxt = last + b[last];
			if (!cache[nxt])
			{
				cache[nxt] = 1;
				par[nxt] = last;
				q.push(nxt);
			}

			last--;
		}
	}
	
	int res = dp[0];
	if (res == INF)
	{
		cout << "-1";
		return 0;
	}

	int cur = 0;
	vector <int> ans;
	while (cur != n)
	{
		ans.push_back(cur);
		cur = back[cur];
	}

	reverse(ans.begin(), ans.end());

	cout << res << '\n';
	for (int v : ans) cout << v << ' ';
}