#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <int> graph[1001];

int dist[1001];
int sz[1001];
int DFS(int v, int p, int d)
{
	dist[v] = d;
	sz[v] = 1;
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		sz[v] += DFS(nv, v, d + 1);
	}
	return sz[v];
}

int isIn[1001];
void DFS2(int v, int p)
{
	isIn[v] = 1;
	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS2(nv, v);
	}
}

vector <int> di[1001];
int qry[1001];

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

		DFS(x, 0, 0);

		int subTree = -1;
		int mx_sz = 0;
		for (auto nv : graph[x])
		{
			if (sz[nv] > mx_sz)
			{
				mx_sz = sz[nv];
				subTree = nv;
			}
		}

		memset(isIn, 0, sizeof isIn);
		DFS2(subTree, x);

		int mx = 0;
		for (int i = 0; i <= 1000; i++) di[i].clear();
		for (int i = 1; i <= n; i++)
		{
			if (isIn[i]) continue;
			di[dist[i]].push_back(i);
			mx = max(mx, dist[i]);
		}

		memset(qry, -1, sizeof qry);
		int l = 0, r = min(mx, d) + 1;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			cout << "? " << di[m].size();
			for (int v : di[m]) cout << ' ' << v;
			cout << endl;

			cin >> x >> d;
			qry[m] = x;

			if (d == minD)
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}

		if (qry[l] == -1)
		{
			cout << "? " << di[l].size();
			for (int v : di[l]) cout << ' ' << v;
			cout << endl;

			cin >> x >> d;
			qry[l] = x;
		}

		x = qry[l];

		DFS(x, 0, 0);

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