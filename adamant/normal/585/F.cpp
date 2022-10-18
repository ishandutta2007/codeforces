#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e4, sigma = 10;

int to[maxn][sigma], link[maxn], len[maxn];
int sz = 1;

void add_str(string s)
{
	int v = 0;
	for(auto c: s)
	{
		c -= '0';
		if(!to[v][c])
		{
			len[sz] = len[v] + 1;
			to[v][c] = sz++;
		}
		v = to[v][c];
	}
}

void push_links()
{
	int q[maxn];
	int st = 0, fi = 1;
	q[0] = 0;
	while(st < fi)
	{
		int v = q[st++];
		int u = link[v];
		for(int c = 0; c < sigma; c++)
		{
			if(to[v][c])
			{
				link[to[v][c]] = v ? to[u][c] : 0;
				q[fi++] = to[v][c];
			}
			else
			{
				to[v][c] = to[u][c];
			}
		}
	}
}
const int maxd = 51;

int dp[maxd][maxn][2][2][2];

const int mod = 1e9 + 7;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, x, y;
	cin >> s >> x >> y;
	int d = x.size();
	for(int i = 0; i < s.size(); i++)
		add_str(s.substr(i, d / 2 + 1));
	push_links();
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0][0] = 1;
	for(int i = 1; i <= d; i++)
	{
		for(int v = 0; v < sz; v++)
		{
			for(int c = 0; c < sigma; c++)
			{
				for(int k1 = 0; k1 < 2; k1++)
					for(int k2 = 0; k2 < 2; k2++)
					{
						int t1 = k1, t2 = k2;
						if(k1 == 0)
						{
							if(y[i - 1] - '0' < c)
								continue;
							if(y[i - 1] - '0' > c)
								t1 = 1;
						
						}
						if(k2 == 0)
						{
							if(x[i - 1] - '0' > c)
								continue;
							if(x[i - 1] - '0' < c)
								t2 = 1;
						}
						if(len[to[v][c]] < d / 2)
							dp[i][to[v][c]][t1][t2][0] += dp[i - 1][v][k1][k2][0];
						else
							dp[i][to[v][c]][t1][t2][1] += dp[i - 1][v][k1][k2][0];
						dp[i][to[v][c]][t1][t2][1] += dp[i - 1][v][k1][k2][1];
						if(dp[i][to[v][c]][t1][t2][0] > mod)
							dp[i][to[v][c]][t1][t2][0] -= mod;
						if(dp[i][to[v][c]][t1][t2][1] > mod)
							dp[i][to[v][c]][t1][t2][1] -= mod;
					}
			}
		}
	}
	int ans = 0;
	for(int v = 0; v < sz; v++)
		for(int k1 = 0; k1 < 2; k1++)
			for(int k2 = 0; k2 < 2; k2++)
			{
				ans += dp[d][v][k1][k2][1];
				if(ans >= mod)
					ans -= mod;
			}
	cout << ans << "\n";
}