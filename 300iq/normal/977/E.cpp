#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 2;

vector <int> g[N];
bool u[N];

bool good = true;

void dfs(int v)
{
	good &= (g[v].size() == 2);
	 u[v] = true;
	 for (int to : g[v])
	 {
		  if (!u[to])
		  {
			   dfs(to);
		  }
	 }
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		 int a, b;
		 cin >> a >> b;
		 a--, b--;
		 g[a].push_back(b);
		 g[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		 if (!u[i])
		 {
			  good = true;
			  dfs(i);
			  ans += good;
		 }
	}
	cout << ans << '\n';
}