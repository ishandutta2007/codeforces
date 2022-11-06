#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

vector<int> adj[maxn];

int d[maxn] , from[maxn] , to[maxn] , ans[maxn];

bool is[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , k;
	cin >> n >> m >> k;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(i);
		adj[b].pb(i);

		d[a]++ , d[b]++;

		from[i] = a , to[i] = b;
	}

	int res = n;
	queue<int> q;

	for(int i = 0; i < n; i++)
		if(d[i] < k)
			q.push(i) , is[i] = 1;

	while(!q.empty())
	{
		res--;
		int v = q.front();
		q.pop();

		for(auto e : adj[v])
		{
			int u = from[e] ^ to[e] ^ v;
			if(!is[u])
			{
				d[u]--;

				if(d[u] < k)
					q.push(u) , is[u] = 1;
			}
		}
	}

	for(int i = m - 1; i >= 0; i--)
	{
		ans[i] = res;

		int v = from[i] , u = to[i];

		if(is[v] || is[u])
			continue;

		d[v]-- , d[u]--;

		if(d[v] < k)
			q.push(v) , is[v] = 1;
		if(d[u] < k)
			q.push(u) , is[u] = 1;

		while(!q.empty())
		{
			res--;

			int v = q.front();
			q.pop();

			for(auto e : adj[v])
			{
				int u = from[e] ^ to[e] ^ v;
				if(e < i && !is[u])
				{
					d[u]--;

					if(d[u] < k)
						q.push(u) , is[u] = 1;
				}
			}
		}

	}

	for(int i = 0; i < m; i++)
		cout << ans[i] << endl;
}