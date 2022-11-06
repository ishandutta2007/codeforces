#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[200001];
ll a[200001];
ll child[200001];
ll sum[200001];

ll DFS(int v)
{
	ll ans = 0;
	sum[v] += a[v];

	if (graph[v].size() == 0)
	{
		child[v] = 1;
		return sum[v];
	}

	for (int nv : graph[v])
	{
		ll res = DFS(nv);
		ans = max(ans, res);

		child[v] += child[nv];
		sum[v] += sum[nv];
	}

	ll here = sum[v] / child[v] + (sum[v] % child[v] ? 1 : 0);
	ans = max(ans, here);

	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p; cin >> p;
		graph[p].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	ll ans = DFS(1);
	cout << ans;
}