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
using namespace std;

const int N = 1010;
bool fs[N][N];
int d[N][N];
int n, m;

void bfs()
{
	bool vis[N][N] = {};
	queue<pii> Q;
	Loop(i, 0, n)
		Loop(j, 0, m)
			if (d[i][j] == 0)
			{
				Q.push({ i,j });
				vis[i][j] = true;
			}
	while (!Q.empty())
	{
		int i = Q.front().first;
		int j = Q.front().second;
		Q.pop();
		if (i > 0 && !vis[i - 1][j])
		{
			vis[i - 1][j] = true;
			d[i - 1][j] = d[i][j] + 1;
			Q.push({ i - 1,j });
		}
		if (j > 0 && !vis[i][j - 1])
		{
			vis[i][j - 1] = true;
			d[i][j - 1] = d[i][j] + 1;
			Q.push({ i,j - 1 });
		}
		if (i < n - 1 && !vis[i + 1][j])
		{
			vis[i + 1][j] = true;
			d[i + 1][j] = d[i][j] + 1;
			Q.push({ i + 1,j });
		}
		if (j < m - 1 && !vis[i][j + 1])
		{
			vis[i][j + 1] = true;
			d[i][j + 1] = d[i][j] + 1;
			Q.push({ i,j + 1 });
		}
	}
}

int main()
{
	FAST;
	memset(d, -1, sizeof(d));
	int t;
	cin >> n >> m >> t;
	char ts[N];
	Loop(i, 0, n)
	{
		cin >> ts;
		Loop(j, 0, m)
			fs[i][j] = ts[j] - '0';
	}
	Loop(i, 0, n)
	{
		Loop(j, 0, m)
		{
			if (i > 0 && fs[i][j] == fs[i - 1][j])
				d[i][j] = 0;
			if (j > 0 && fs[i][j] == fs[i][j - 1])
				d[i][j] = 0;
			if (i < n - 1 && fs[i][j] == fs[i + 1][j])
				d[i][j] = 0;
			if (j < m - 1 && fs[i][j] == fs[i][j + 1])
				d[i][j] = 0;
		}
	}
	bfs();
	while (t--)
	{
		int i, j; ll p;
		cin >> i >> j >> p; i--; j--;
		if (p < d[i][j] || d[i][j] == -1)
			cout << (int)fs[i][j] << '\n';
		else
			cout << (int)(fs[i][j] ^ ((p - d[i][j]) & 1)) << '\n';
	}
}