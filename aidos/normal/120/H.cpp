#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int INF = 1000000000;   

vector<int> u[205];
int match[100000];
int used[205];
int f = 1;

bool dfs(int i)
{
	if (used[i] == f) return false;
	used[i] = f;	
	for (int j = 0; j < u[i].size(); j++)
	{
		int to = u[i][j];
		if (match[to] == -1 || dfs(match[to]))
		{
			match[to] = i;
			return true;
		}
	} 
	return false;
}
  
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<string, int> s;
	vector<string> q;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		int len = tmp.length();
		for (int j = 0; j < (1 << len); j++)
		{
			int bt = 0;
			for (int k = 0; k < len; k++)
				if (j & (1 << k)) bt++;
			if (bt > 4 || bt == 0) continue;
			string v;
			for (int k = 0; k < len; k++)
				if (j & (1 << k)) v += tmp[k];
			if (s.count(v) != 0) u[i].push_back(s[v]);
			else
			{
				q.push_back(v);
				int p = s.size();
				s[v] = p;
				u[i].push_back(p);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		sort(u[i].begin(), u[i].end());
		u[i].erase(unique(u[i].begin(), u[i].end()), u[i].end());
	}
		int m = s.size();
	for (int i = 0; i < m; i++) match[i] = -1;
	

	for (int i = 0; i < n; i++,f++)
		dfs(i);
		
	vector<int> match0(n);
	vector<bool> ok(n);
	for (int i = 0; i < m; i++) if (match[i] != -1) {match0[match[i]] = i; ok[match[i]] = true;}
	for (int i = 0; i < n; i++) if (!ok[i])
	{
		cout << -1;
		return 0;
	}
	
	
	for (int i = 0; i < n; i++)
		cout << q[match0[i]] << endl;

	return 0;
}