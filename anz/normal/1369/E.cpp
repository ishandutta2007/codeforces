#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int w[100001];

int x[200001];
int y[200001];
vector <int> graph[100001];
int in[100001];

bool cache[200001];
queue <int> q;
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];

	for (int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		graph[x[i]].push_back(i);
		graph[y[i]].push_back(i);
		in[x[i]]++, in[y[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (in[i] <= w[i]) q.push(i);
	}

	while (!q.empty())
	{
		int f = q.front(); q.pop();

		for (int h : graph[f])
		{
			if (cache[h]) continue;
			cache[h] = 1;
			ans.push_back(h);

			if(x[h] != f)
			{
				if (--in[x[h]] <= w[x[h]]) q.push(x[h]);
			}
			else
			{
				if (--in[y[h]] <= w[y[h]]) q.push(y[h]);
			}
		}
	}

	if (ans.size() < m)
	{
		cout << "DEAD\n";
		return 0;
	}

	cout << "ALIVE\n";
	reverse(ans.begin(), ans.end());
	for (int it : ans) cout << it << ' ';
}