#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[500001];

vector <int> idx[500001];
int cnt[500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		int d; cin >> d;
		idx[d].push_back(i + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		set <int> plus;
		for (int v : idx[i])
		{
			if (plus.find(v) != plus.end())
			{
				cout << -1;
				return 0;
			}

			if (cnt[v] != i - 1)
			{
				cout << -1;
				return 0;
			}

			for (int nv : graph[v])
				plus.insert(nv);
		}

		for (int p : plus)
		{
			cnt[p]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int v : idx[i]) cout << v << ' ';
	}
}