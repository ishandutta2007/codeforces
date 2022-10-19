#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define mp make_pair
#define lli long long int
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m, int a)
{
	if (x >= a && y >= a && x < n && y < m)
	{
		return true;
	}
	return false;
}
using namespace std;
const int N = 5e5 + 20;
bool col[N], col1[N];
int sm;
vector <int> g[N], gr[N];
int pat[N];
int n, m;
void dfs(int v)
{
	col[v] = true;
	sm++;
	for (int i = 0; i < gr[v].size(); i++)
	{
		if (!col1[gr[v][i]])
		{
			col1[gr[v][i]] = true;
			for (int j = 0; j < g[gr[v][i]].size(); j++)
			{
				if (!col[g[gr[v][i]][j]])
					dfs(g[gr[v][i]][j]);
			}
		}
	}
}
bool coll1[N];
void dfs1(int v)
{
	pat[v] = sm;
	for (int i = 0; i < gr[v].size(); i++)
	{
		if (!coll1[gr[v][i]])
		{
			coll1[gr[v][i]] = true;
			for (int j = 0; j < g[gr[v][i]].size(); j++)
			{
				if (!pat[g[gr[v][i]][j]])
					dfs1(g[gr[v][i]][j]);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b;
			cin >> b;
			g[i].push_back(b);
			gr[b].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!col[i])
		{
			sm = 0;
			dfs(i);
			dfs1(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << pat[i] << " ";
	}
	return 0;
}