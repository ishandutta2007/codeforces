#include<bits/stdc++.h>
using namespace::std;
 
#define ll long long
#define pb push_back

const int maxn = 600 + 20;
const int maxm = maxn * maxn + 20;

vector<int> adj[maxn];

int from[maxm] , to[maxm] , w[maxm];

int d[maxn], ans[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;

		adj[a].pb(i);

		from[i] = a , to[i] = b , w[i] = c;
	}

	for(int v = 0; v < n; v++)
	{
		memset(d, 63 , sizeof d);
		for(auto e : adj[v])
			d[to[e]] = w[e];
		for(int _ = 0; _ < n; _++)
		{
			int res = -1;
			for(int u = 0; u < n; u++)
				if(d[u] != -1 && (res == -1 || d[u] < d[res]))
					res = u;

			if(res == -1)
				break;

			d[(res + 1) % n] = min(d[(res + 1) % n], d[res] + 1);
			for(auto e : adj[res])
			{
				int dest = (to[e] + d[res]) % n;
				d[dest] = min(d[dest], d[res] + w[e]);
			}

			ans[res] = d[res];
			d[res] = -1;
		}

		ans[v] = 0;
		for(int u = 0; u < n; u++)
			cout << ans[u] << " ";
		cout << endl;
	}
}