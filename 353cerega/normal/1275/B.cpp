//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <array>
#include <string>
#include <set>
#include <map>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <deque>

#define X first
#define Y second

using ll = long long;
using ld = long double;

using namespace std;

int n;
vector<vector<int>> g;

void solve()
{
	g.clear();
	cin >> n;
	g.resize(n-2);
	vector < pair<pair<int, int>, int>> edges;
	for (int i = 0; i < n - 2; i++)
	{
		vector<int> kok(3);
		cin >> kok[0] >> kok[1] >> kok[2];
		kok[0]--;
		kok[1]--;
		kok[2]--;
		sort(kok.begin(), kok.end());
		edges.push_back({ {kok[0],kok[1]},i });
		edges.push_back({ { kok[1],kok[2] },i });
		edges.push_back({ { kok[0],kok[2] },i });
	}
	sort(edges.begin(), edges.end());
	vector<vector<int>> tr(n);
	for (int i = 0; i < edges.size(); )
	{
		if (i == edges.size() - 1 or edges[i].X!=edges[i+1].X)
		{
			tr[edges[i].X.X].push_back(edges[i].X.Y);
			tr[edges[i].X.Y].push_back(edges[i].X.X);
			//cout << edges[i].X.X << " " << edges[i].X.Y << endl;
			i++;
			continue;
		}
		int u = edges[i].Y, v = edges[i+1].Y;
		g[u].push_back(v);
		g[v].push_back(u);
		//cout << u << " " << v << endl;
		i += 2;
	}
	int st = 0, pr = -1;
	if (tr[st].size() == 0)
	{
		cout << st + 1 << " ";
	}
	else
	{
		while (pr == -1 or st != 0)
		{
			for (int i = 0; i < tr[st].size(); i++)
			{
				if (tr[st][i] != pr)
				{
					cout << st + 1 << " ";
					pr = st;
					st = tr[st][i];
					break;
				}
			}
		}
	}
	
	cout << endl;
	if (n == 3)
	{
		cout << 1 << endl;
		return;
	}
	vector<int> q;
	vector<int> lft(n - 2);
	for (int i = 0; i < n - 2; i++)
	{
		lft[i] = g[i].size()-1;
		if (g[i].size() == 1)
		{
			q.push_back(i);
		}

	}
	while (q.size() > 0)
	{
		int u = q.back();
		q.pop_back();
		cout << u+1 << " ";
		for (int i = 0; i < g[u].size(); i++)
		{
			lft[g[u][i]]--;
			if (lft[g[u][i]] == 0)
			{
				q.push_back(g[u][i]);
			}
		}
	}
	cout << endl;
	
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		solve();
	}

}



/*string s;
int k1, k2, l;
s = "a";
cout << s << endl;
cin >> k1;
if (k1 == 0)
{
return 0;
}
l = k1;
s = "b";
cout << s << endl;
cin >> k2;
l = min(k2, l);
if (k2 == 0)
{
return 0;
}
l++;
s = "";
if (k2 < k1)
{
for (int i = 0; i < l; i++)
{
s += 'b';
}
cout << s << endl;
return 0;
}
if (k1 < k2)
{
for (int i = 0; i < l; i++)
{
s += 'a';
}
cout << s << endl;
return 0;
}
for (int i = 0; i < l; i++)
{
s += 'a';
}
s[0] = 'b';*/