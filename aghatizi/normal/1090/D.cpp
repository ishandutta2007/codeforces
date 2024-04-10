#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

vector<int> adj[maxn];

bool visited[maxn] , fn[maxn];

int total , res1[maxn] , res2[maxn];

set<pair<int , int> > st;

void bfs(int a , int b)
{
	queue<int> q;
	q.push(a);
	q.push(b);
	visited[a] = visited[b] = 1;

	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		fn[v] = 1;

		res2[v] = -1;
		for(auto u : adj[v])
			if(fn[u])
				res2[v] = max(res2[v] , res2[u]);
		res2[v]++;
		res1[v] = total++;
		
		for(auto u : adj[v])
			if(!visited[u])
			{
				q.push(u);
				visited[u] = 1;
			}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 0; i < m; i++)
	{
		int a , b;
		cin >> a >> b;
		a-- , b--;

		adj[a].pb(b);
		adj[b].pb(a);

		st.insert(make_pair(min(a , b) , max(a , b)));
	}

	int a = -1 , b = -1;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(!st.count(make_pair(i , j)))
			{
				a = i;
				b = j;
				i = n;
				break;
			}

	if(a == -1)
		return cout << "NO" << endl , 0;

	bfs(a , b);

	for(int i = 0; i < n; i++)
		if(!visited[i])
			res1[i] = total , res2[i] = total , total++;

	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << res1[i] + 1 << " ";
	cout << endl;

	for(int i = 0; i < n; i++)
		cout << res2[i] + 1 << " ";
	cout << endl;
}