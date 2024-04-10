#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

struct DirectedEulerPath
{
	int n;
	vector<vector<int> > g;
	vector<int> path;

	void init(int _n)
	{
		n = _n;
		g = vector<vector<int> > (n + 1, vector<int> ());
		path.clear();
	}

	void add_edge(int u, int v)
	{
		g[u].push_back(v);
	}

	void dfs(int u)
	{
		while(g[u].size())
		{
			int v = g[u].back();
			g[u].pop_back();
			dfs(v);
		}
		path.push_back(u);
	}

	bool getPath()
	{
		int ctEdges = 0;
		vector<int> outDeg, inDeg;
		outDeg = inDeg = vector<int> (n + 1, 0);
		for(int i = 1; i <= n; i++)
		{
			ctEdges += g[i].size();
			outDeg[i] += g[i].size();
			for(auto &u:g[i])
				inDeg[u]++;
		}
		int ctMiddle = 0, src = 1;
		for(int i = 1; i <= n; i++)
		{
			if(abs(inDeg[i] - outDeg[i]) > 1)
				return 0;
			if(inDeg[i] == outDeg[i])
				ctMiddle++;
			if(outDeg[i] > inDeg[i])
				src = i;
		}
		if(ctMiddle != n && ctMiddle + 2 != n)
			return 0;
		dfs(src);
		reverse(path.begin(), path.end());
		return (path.size() == ctEdges + 1);
	}
};

int n, k;
string rev[N];
string s[N];
DirectedEulerPath euler;
map<string, int> comp;

int32_t main()
{
	IOS;
	cin >> n;
	int k = 3;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		comp[s[i].substr(0, k - 1)];
		comp[s[i].substr(1, k - 1)];
	}
	int ct = 0;
	for(auto &it:comp)
	{
		it.second = ++ct;
		rev[ct] = it.first;
	}
	euler.init(ct);
	for(int i = 1; i <= n; i++)
	{
		int u = comp[s[i].substr(0, k - 1)];
		int v = comp[s[i].substr(1, k - 1)];
		euler.add_edge(u, v);
	}
	if(!euler.getPath())
		cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		string ans = rev[euler.path[0]];
		for(int i = 1; i < euler.path.size(); i++)
			ans += rev[euler.path[i]].back();
		cout << ans << endl;
	}
	return 0;
}