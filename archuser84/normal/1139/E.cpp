#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 5010;
vector<int> A[N];
int match[N];
int n, m;
int p[N];
int c[N];
bool removed[N] = {};
pii Q[N];
bool vis[N];

bool dfs(int u)
{
	vis[u] = true;
	for (int v : A[u])
	{
		if (vis[match[v]])
			continue;
		if (match[v] == -1)
		{
			match[v] = u;
			return true;
		}
		if (dfs(match[v]))
		{
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	FAST;
	memset(match, -1, sizeof(match));
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> p[i];
	Loop(i, 0, n)
	{
		cin >> c[i];
		c[i]--;
	}
	int d;
	cin >> d;
	Loop(i, 0, d)
	{
		cin >> Q[i].first;
		Q[i].first--;
		removed[Q[i].first] = true;
	}
	reverse(Q, Q + d);
	int v = 0;
	Loop(i, 0, n)
	{
		if (removed[i])
			continue;
		A[p[i]].push_back(c[i]);
	}
	Loop(i, 0, d)
	{
		while (v < m)
		{
			memset(vis, 0, sizeof(vis));
			if (dfs(v))
				v++;
			else
				break;
		}
		Q[i].second = v;
		A[p[Q[i].first]].push_back(c[Q[i].first]);
	}
	reverse(Q, Q + d);
	Loop(i, 0, d)
	{
		cout << Q[i].second << '\n';
	}
}