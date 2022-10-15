#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100007;

int n, m;
int h, t;

vector < vector <int> > a;
int upd[MAXN], cnt;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d %d %d", &n, &m, &h, &t);
	a.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for (int u = 1; u <= n; u++)
	{
		cnt++;
		for (int j = 0; j < (int)a[u].size(); j++)
			upd[a[u][j]] = cnt;

		for (int i = 0; i < (int)a[u].size(); i++)
		{
			int v = a[u][i];
			if ((int)a[u].size() - 1 < h || (int)a[v].size() - 1 < t) continue;
			int x = 0;
			for (int j = 0; j < (int)a[v].size(); j++)
				x += upd[a[v][j]] == cnt;
			if ((int)a[u].size() - 1 + (int)a[v].size() - 1 - x >= h + t)
			{
				vector <int> l, r, c;
				for (int j = 0; j < (int)a[v].size(); j++)
					if (upd[a[v][j]] == cnt)
						c.push_back(a[v][j]);
				cnt++;
				for (int j = 0; j < (int)a[v].size(); j++)
				{
					if (upd[a[v][j]] != cnt - 1 && a[v][j] != u)
						r.push_back(a[v][j]);
					upd[a[v][j]] = cnt;
				}
				for (int j = 0; j < (int)a[u].size(); j++)
					if (upd[a[u][j]] != cnt && a[u][j] != v)
						l.push_back(a[u][j]);
				cout << "YES" << endl;
				cout << u << " " << v << endl;
//				cout << l.size() << " " << c.size() << " " << r.size() << endl;
				for (int j = 0; (int)l.size() < h || (int)r.size() < t; j++)
				{
					if ((int)l.size() < h)
						l.push_back(c[j]);
					else
						r.push_back(c[j]);
				}
				l.resize(h);
				r.resize(t);
				for (int j = 0; j < (int)l.size(); j++)
				{
					if (j) cout << " ";
					cout << l[j];
				}
				cout << endl;
				for (int j = 0; j < (int)r.size(); j++)
				{
					if (j) cout << " ";
					cout << r[j];
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	
	return 0;
}