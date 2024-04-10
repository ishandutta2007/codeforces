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

ll Count(int n,int a, int b)
{
	ll A = 0, B = 0;

	bool visited[200000] = { 0 }; visited[a] = true; visited[b] = true;
	int queue[200000]; queue[0] = a;
	int qs = 0, qe = 1;
	while(qe - qs > 0)
	{
		int u = queue[qs++];
		for (int v : E[u])
		{
			if (!visited[v])
			{
				visited[v] = true;
				queue[qe++] = v;
				A++;
			}
		}
	}

	memset(visited, false, n); visited[a] = true; visited[b] = true;
	queue[0] = b;
	qs = 0; qe = 1;
	while(qe - qs > 0)
	{
		int u = queue[qs++];
		for (int v : E[u])
		{
			if (!visited[v])
			{
				visited[v] = true;
				queue[qe++] = v;
				B++;
			}
		}
	}

	ll M = A + B - (n - 2);
	A -= M; B -= M;
	return A * B;
}

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		Loop(j, 0, m)
		{
			int v, u;
			cin >> v >> u; u--; v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}

		cout << Count(n, a - 1, b - 1) << '\n';
		
		Loop(i, 0, n)
			E[i].clear();
	}
}