#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> graph[200001];
vector <int> graph_a[200001];
int dist[200001];

int k;
int p[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph_a[v].push_back(u);
	}

	cin >> k;
	for (int i = 0; i < k; i++) cin >> p[i];

	memset(dist, -1, sizeof dist);
	queue <int> q;
	dist[p[k - 1]] = 0;
	q.push(p[k - 1]);

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (auto nv : graph_a[v])
		{
			if (dist[nv] != -1) continue;
			dist[nv] = dist[v] + 1;
			q.push(nv);
		}
	}

	int mnAns = 0, mxAns = 0;

	for (int i = 0; i < k - 1; i++)
	{
		int v = p[i];
		int nv = p[i + 1];

		if (dist[v] - 1 == dist[nv])
		{
			bool flag = false;
			for (auto tv : graph[v])
			{
				if (tv == nv) continue;
				if (dist[nv] == dist[tv])
				{
					flag = true;
					break;
				}
			}

			if (flag) mxAns++;
		}
		else
		{
			mnAns++;
			mxAns++;
		}
	}

	cout << mnAns << ' ' << mxAns;
}