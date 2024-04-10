#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200000;
int n, m, k;
vector<int> A[N], T[N];
int p[N];
int par[N];
int d[N];

void bfs(int t)
{
	d[t] = 0;
	int queue[N]; queue[0] = t;
	int qs = 0, qe = 1;
	bool vis[N] = {}; vis[t] = true;
	par[t] = -1;
	while (qe > qs)
	{
		int u = queue[qs++];
		for (int v : T[u])
		{
			if (!vis[v])
			{
				vis[v] = true;
				queue[qe++] = v;
				d[v] = d[u] + 1;
				par[v] = u;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		T[v].push_back(u);
	}
	cin >> k;
	Loop(i, 0, k)
	{
		cin >> p[i];
		p[i]--;
	}
	bfs(p[k - 1]);
	int a = 0, b = 0;
	Loop(i, 0, k - 1)
	{
		if (k - i - 1 > d[p[i]] && d[par[p[i]]] != d[p[i + 1]])
		{
			a++;
			b++;
		}
		else
		{
			for (int v : A[p[i]])
			{
				if (v != p[i + 1] && d[v] + 1 == d[p[i]])
				{
					b++;
					break;
				}
			}
		}
	}
	cout << a << " " << b;
}