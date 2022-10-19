#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1000;
int n;

pair<int, int> g[N][N];
char ans[N][N];
int cnt = 0;

bool vis[N][N] = {};
void dfs(int a,int b,char s)
{
	cnt++;
	ans[a][b] = s;
	vis[a][b] = true;
	if (a > 0 && g[a - 1][b] == g[a][b] && !vis[a - 1][b])
		dfs(a - 1, b, 'D');
	if (a < n-1 && g[a + 1][b] == g[a][b] && !vis[a + 1][b])
		dfs(a + 1, b, 'U');
	if (b > 0 && g[a][b - 1] == g[a][b] && !vis[a][b - 1])
		dfs(a, b - 1, 'R');
	if (b < n-1 && g[a][b + 1] == g[a][b] && !vis[a][b + 1])
		dfs(a, b + 1, 'L');
}

pair<pair<int,int>, char> rN;
bool visN[N][N] = {};
void dfsN(int a, int b)
{
	visN[a][b] = true;
	if (a > 0 && g[a - 1][b] == g[a][b])
	{
		if (!visN[a - 1][b])
			dfsN(a - 1, b);
		else
			rN = { {a - 1,b},'D' };
	}
	if (a < n - 1 && g[a + 1][b] == g[a][b])
	{
		if (!visN[a + 1][b])
			dfsN(a + 1, b);
		else
			rN = { {a + 1,b},'U' };
	}
	if (b > 0 && g[a][b - 1] == g[a][b])
	{
		if (!visN[a][b - 1])
			dfsN(a, b - 1);
		else
			rN = { {a,b - 1},'R' };
	}
	if (b < n - 1 && g[a][b + 1] == g[a][b])
	{
		if (!visN[a][b + 1])
			dfsN(a, b + 1);
		else
			rN = { {a,b + 1},'L' };
	}
}

int main()
{
	FAST;
	cin >> n;
	bool an = true;
	Loop(i,0,n)
		Loop(j, 0, n)
		{
			cin >> g[i][j].first >> g[i][j].second;
			g[i][j].first--; g[i][j].second--;
		}
	Loop(i, 0, n)
	{
		Loop(j, 0, n)
		{
			if (g[i][j] == make_pair(i, j))
				dfs(i, j, 'X');
			else if(g[i][j].first < 0 && !visN[i][j])
			{
				rN.second = '\0';
				dfsN(i, j);
				if (rN.second == '\0')
					an = false;
				else
					dfs(rN.first.first, rN.first.second, rN.second);
			}
		}
	}
	if (!ans || cnt < n * n)
	{
		cout << "INVALID\n";
	}
	else
	{
		cout << "VALID\n";
		Loop(i, 0, n)
		{
			Loop(j, 0, n)
				cout << ans[i][j];
			cout << '\n';
		}
	}
}