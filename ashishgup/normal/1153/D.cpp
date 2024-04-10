#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, leaves = 0;
int a[N], subtree[N], mark[N];
vector<int> g[N];

void dfs0(int u)
{
	subtree[u] = (g[u].size() == 0);
	leaves += (g[u].size() == 0);
	mark[u] = (g[u].size() == 0);
	for(auto &it:g[u])
	{
		dfs0(it);
		subtree[u] += subtree[it];
	}
}

int dfs(int u)
{
	vector<int> v;
	if(mark[u])
		return 1;
	for(auto &it:g[u])
		v.push_back(dfs(it));
	sort(v.begin(), v.end());
	int lost = 0;
	if(a[u] == 1)
		return v[0];
	else
	{
		int sum = 0, mx = 0;
		for(auto &it:v)
			sum += it;
		return sum;
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n; i++)
	{
		int par;
		cin >> par;
		g[par].push_back(i);
	}
	dfs0(1);
	int lost = dfs(1);
	cout << leaves - lost + 1;
	return 0;
}