#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int M = 10000;
const int G = 1000;
int d[M];
int r, g, n, m;
bool vis[M][G] = {};
int dis[M][G];

int bfs()
{
	deque<pair<int, int>> Q;
	vis[0][0] = true;
	dis[0][0] = 0;
	Q.push_back({ 0,0 });
	int ans = Mod1;
	while (!Q.empty())
	{
		int v = Q.front().first;
		int t = Q.front().second;
		Q.pop_front();
		if (v > 0)
		{
			if (g - t > d[v] - d[v - 1])
			{
				int t2 = t + d[v] - d[v - 1];
				if (!vis[v - 1][t2])
				{
					Q.push_front({ v - 1, t2 });
					vis[v - 1][t2] = true;
					dis[v - 1][t2] = dis[v][t];
				}
			}
			else if (g - t == d[v] - d[v - 1])
			{
				if (!vis[v - 1][0])
				{
					Q.push_back({ v - 1, 0 });
					vis[v - 1][0] = true;
					dis[v - 1][0] = dis[v][t] + 1;
				}
			}
		}
		if (v < m-1)
		{
			if (g - t > d[v + 1] - d[v])
			{
				int t2 = t + d[v + 1] - d[v];
				if (!vis[v + 1][t2])
				{
					Q.push_front({ v + 1, t2 });
					vis[v + 1][t2] = true;
					dis[v + 1][t2] = dis[v][t];
				}
			}
			else if (g - t == d[v + 1] - d[v])
			{
				if (!vis[v + 1][0])
				{
					Q.push_back({ v + 1, 0 });
					vis[v + 1][0] = true;
					dis[v + 1][0] = dis[v][t] + 1;
				}
			}
		}
		if (v == m - 1)
			ans = min(ans, dis[v][t] * (r + g) + t - r * (t == 0));
	}
	return ans == Mod1 ? -1 : ans;
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
		cin >> d[i];
	cin >> g >> r;
	sort(d, d + m);
	cout << bfs();
}