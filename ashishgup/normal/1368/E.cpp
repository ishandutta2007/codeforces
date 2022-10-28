#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;
 
int n, m;
vector<int> v;
bool first[N], second[N];
set<int> g[N];
 
void work()
{
	v.clear();
	for(int i = 1; i <= n; i++)
	{
		if(second[i])
		{
			v.push_back(i);
			continue;
		}
		for(auto &it:g[i])
		{
			if(first[i])
				second[it] = 1;
			else
				first[it] = 1;
		}
	}
	assert(v.size() <= 4 * n / 7);
}
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			g[i].clear();
			first[i] = second[i] = 0;
		}
		for(int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].insert(v);
		}
		work();
		cout << v.size() << endl;
		for(auto &it:v)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}