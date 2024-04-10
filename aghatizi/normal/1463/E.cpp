#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 3e5 + 20;

int p[maxn] , where[maxn] , from[maxn] , to[maxn];

deque<int> dq[maxn] , topol , adj[maxn];

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : adj[v])
		if(!visited[u])
			dfs(u);
	topol.pb(v);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> p[i] , p[i]--;
		dq[i].pb(i);
		where[i] = i;
	}

	for(int i = 0; i < k; i++)
	{
		int x , y;
		cin >> x >> y;
		x-- , y--;

		from[i] = x , to[i] = y;

		x = where[x] , y = where[y];

		if(dq[x].size() > dq[y].size())
		{
			for(auto tmp : dq[y])
				dq[x].pb(tmp) , where[tmp] = x;
			dq[y] = {};
		}
		else
		{
			reverse(dq[x].begin() , dq[x].end());
			for(auto tmp : dq[x])
				dq[y].push_front(tmp) , where[tmp] = y;
			dq[x] = {};
		}
	}

	for(int i = 0; i < n; i++)
	{
		int x = i , y = p[i];
		if(p[i] == -1)
			continue;

		x = where[x] , y = where[y];

		if(x != y)
			adj[x].pb(y);
	}

	for(int i = 0; i < n; i++)
		if(!dq[i].empty() && !visited[i])
			dfs(i);

	vector<int> ans;
	for(auto v : topol)
		for(auto u : dq[v])
			where[u] = ans.size() , ans.pb(u);

	for(int i = 0; i < n; i++)
		if(p[i] >= 0 && where[p[i]] > where[i])
			return cout << 0 << endl , 0;

	for(int i = 0; i < k; i++)
		if(where[from[i]] != where[to[i]] - 1)
			return cout << 0 << endl , 0;

	for(auto v : ans)
		cout << v + 1 << " ";
	cout << endl;
}