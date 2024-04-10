#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

vector<int> E[200000];

int bfs(int r)
{
	int queue[200000]; queue[0] = r;
	int qs = 0, qe = 1;
	bool visited[200000] = { 0 }; visited[r] = true;
	int depth[200000]; depth[r] = 0;

	while (true)
	{
		int u = queue[qs++];
		for (int v : E[u])
		{
			if (!visited[v])
			{
				visited[v] = true;
				depth[v] = depth[u] + 1;
				queue[qe++] = v;
			}
		}
		
		if (qe - qs == 0)
			return u;
	}
}

int bfsLimit(int r,int L1,int L2,int &length)
{
	int queue[200000]; queue[0] = r;
	int qs = 0, qe = 1;
	bool visited[200000] = { 0 }; visited[r] = true;
	int depth[200000]; depth[r] = 0;

	while (true)
	{
		int u = queue[qs++];
		for (int v : E[u])
		{
			if (!visited[v] && v != L1 && v != L2)
			{
				visited[v] = true;
				depth[v] = depth[u] + 1;
				queue[qe++] = v;
			}
		}
		
		if (qe - qs == 0)
		{
			length = depth[u];
			return u;
		}
	}
}

vector<int> path;
int bfsPath(int r)
{
	int queue[200000]; queue[0] = r;
	int qs = 0, qe = 1;
	int parent[200000] = { 0 }; parent[r] = -1;
	int depth[200000]; depth[r] = 0;
	int ans;

	while (true)
	{
		int u = queue[qs++];
		for (int v : E[u])
		{
			if (v != parent[u])
			{
				parent[v] = u;
				depth[v] = depth[u] + 1;
				queue[qe++] = v;
			}
		}
		
		if (qe - qs == 0)
		{
			ans = u;
			break;
		}
	}

	int i = ans;
	while (i != -1)
	{
		path.push_back(i);
		i = parent[i];
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	Loop(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	int A = bfs(0);
	int B = bfsPath(A);
	int max;
	int C = bfsLimit(path[1], path[0], path[2], max);
	Loop(i, 2, path.size() - 1)
	{
		int h, l;
		h = bfsLimit(path[i], path[i - 1], path[i + 1], l);
		if (l > max)
		{
			max = l;
			C = h;
		}
	}

	cout << path.size() - 1 + max << '\n';
	cout << A + 1 << ' ' << B + 1 << ' ' << C + 1 << ' ';
}