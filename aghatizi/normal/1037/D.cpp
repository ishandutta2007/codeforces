#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int h[maxn] , a[maxn] , pos[maxn] , nxt[maxn];

vector<int> adj[maxn];

void predfs(int v , int p = -1)
{
	for(auto u : adj[v])
		if(u != p)
		{
			h[u] = h[v] + 1;
			predfs(u , v);
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n - 1; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	predfs(0);

	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i]-- , pos[a[i]] = i;

	for(int i = 0; i + 1 < n; i++)
		if(h[a[i]] > h[a[i + 1]])
			return cout << "No" << endl , 0;

	int pt = 1;
	for(int i = 0; i < n; i++)
	{
		int v = a[i];
		int mn = 1e9 , mx = -1 , T = 0;

		for(auto u : adj[v])
			if(h[u] > h[v])
			{
				T++;
				mn = min(mn , pos[u]);
				mx = max(mx , pos[u]);
			}

		if(!T)
			continue;

		if(mx - mn + 1 != T || mn != pt)
			return cout << "No" << endl , 0;

		pt += T;
	}

	cout << "Yes" << endl;
}