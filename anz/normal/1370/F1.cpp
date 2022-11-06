#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[1001];

int cache[1001];
int dist[1001];
void DFS(int v, int d)
{
	cache[v] = 1;
	dist[v] = d;
	for (int nv : graph[v])
	{
		if (cache[nv]) continue;
		DFS(nv, d + 1);
	}
}

vector <int> di[1001];

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 0; i < n - 1; i++)
		{
			int u, v; cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		cout << "? " << n;
		for (int i = 1; i <= n; i++) cout << ' ' << i;
		cout << endl;

		int x, d; cin >> x >> d;
		int minD = d;

		memset(cache, 0, sizeof cache);
		DFS(x, 0);

		int mx = 0;
		for (int i = 0; i <= 1000; i++) di[i].clear();
		for (int i = 1; i <= n; i++)
		{
			di[dist[i]].push_back(i);
			mx = max(mx, dist[i]);
		}
			

		int l = 1, r = mx + 1;

		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			cout << "? " << di[m].size();
			for (int v : di[m]) cout << ' ' << v;
			cout << endl;

			cin >> x >> d;
			if (d == minD)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}

		cout << "? " << di[l].size();
		for (int v : di[l]) cout << ' ' << v;
		cout << endl;

		cin >> x >> d;

		memset(cache, 0, sizeof cache);
		DFS(x, 0);

		vector <int> tmp;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == minD) tmp.push_back(i);
		}

		cout << "? " << tmp.size();
		for (int v : tmp) cout << ' ' << v;
		cout << endl;

		int lx, ld; cin >> lx >> ld;

		cout << "! " << x << ' ' << lx << endl;

		string res; cin >> res;
		if (res != "Correct") return 0;
	}
}