#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

vector<int> out[maxn] , in[maxn] , topol , last;

int c;

bool visited[maxn];

void dfs(int v)
{
	visited[v] = 1;
	for(auto u : out[v])
		if(!visited[u])
			dfs(u);
	
	topol.pb(v);
}

void sfd(int v)
{
	visited[v] = 1;
	last.pb(v);
	for(auto u : in[v])
		if(!visited[u])
			sfd(u);
}

void solve()
{
	int n , m;
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		out[i].clear() , in[i].clear() , visited[i] = 0;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		out[a].pb(b);
		in[b].pb(a);
	}

	topol.clear();
	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs(i);

	reverse(topol.begin() , topol.end());
	c = 0;
	fill(visited , visited + n , 0);

	for(auto v : topol)
		if(!visited[v])
			last.clear() , sfd(v) , c++;
	for(auto v : last)
		visited[v] = 0;

	if(c == 1)
	{
		cout << "No" << endl;
		return;
	}

	cout << "Yes" << endl;
	cout << last.size() << " " << n - (int)last.size() << endl;
	for(auto x : last)
		cout << x + 1 << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		if(visited[i])
			cout << i + 1 << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}