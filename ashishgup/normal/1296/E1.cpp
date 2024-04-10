#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;
bool vis[N];
int col[N];
set<int> g[N];

bool dfs(int u, int c)
{
	if(vis[u])
	{
		if(col[u] != c)
			return false;
		return true;
	}
	vis[u] = 1;
	col[u] = c;
	for(auto &it:g[u])
		if(!dfs(it, c ^ 1))
			return false;
	return true;
}

int32_t main()
{
	IOS;
	cin >> n >> s;
	for(int i = 0; i < n; i++)	
	{
		for(int j = i + 1; j < n; j++)
		{
			if(s[i] > s[j])
			{
				g[i].insert(j);
				g[j].insert(i);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!vis[i])
		{
			if(!dfs(i, 0))
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
		cout << col[i];
	return 0;
}