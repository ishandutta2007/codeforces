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

const int N = 2000;
vector<int> A[N];
bool ban[N] = {};
int n;

pair<int, int> dfsmax;
int P[N];
void dfs(int u, int p,int d)
{
	P[u] = p;
	if (d > dfsmax.second)
		dfsmax = { u,d };
	for (int v : A[u])
		if (v != p && !ban[v])
			dfs(v, u, d + 1);
}

pair<int, int> far;
void findFar(int u)
{
	dfsmax.second = -1;
	dfs(u, -1, 0);
	far.first = dfsmax.first;
	dfsmax.second = -1;
	dfs(far.first, -1, 0);
	far.second = dfsmax.first;
}

void Ban(int u)
{
	int x = far.second;
	if (x != u)
	{
		while (P[x] != u)
			x = P[x];
		ban[x] = true;
	}
	if(P[u] != -1)
		ban[P[u]] = true;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	int u = 0;
	while (true)
	{
		findFar(u);
		if (far.first == far.second)
			break;
		printf("? %i %i\n", far.first + 1, far.second + 1);
		fflush(stdout);
		cin >> u; u--;
		Ban(u);
	}
	printf("! %i",far.first + 1);
	fflush(stdout);
}