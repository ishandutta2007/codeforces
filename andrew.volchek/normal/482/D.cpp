#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define lll __int128
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const ll mod = 1000000007;
const int maxn = 100005;

vector < int > g[maxn];

ll dp[maxn][2][2];

ll bpow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

void dfs(int v, int p)
{
	for (int to : g[v])
	{
		if (to == p)
			continue;
		dfs(to, v);
	}
	
	if (!g[v].empty())
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i != j)
				{
					for (int iter = 0; iter < 2; iter++)
					{
						ll a[] = { i, 1 - i };
						
						for (int h = 0; h < g[v].size(); h++)
						{
							int to = g[v][h];
							if (iter == 1)
								to = g[v][g[v].size() - 1 - h];
							
							ll x = ((dp[to][0][0] * a[0]) % mod) + ((dp[to][1][0] * a[1]) % mod);
							if (x >= mod)
								x -= mod;
								
							ll y = ((dp[to][1][1] * a[1]) % mod) + ((dp[to][0][1] * a[0]) % mod);
							if (y >= mod)
								y -= mod;
							
							a[0] += x;
							if (a[0] >= mod)
								a[0] -= mod;
							a[1] += y;
							if (a[1] >= mod)
								a[1] -= mod;
						}
						
						dp[v][i][j] += a[j];
						if (dp[v][i][j] >= mod)
							dp[v][i][j] -= mod;
					}
					
					ll c = 1;
					for (int h = 0; h < g[v].size(); h++)
					{
						int to = g[v][h];
						
						c = (c * (1LL + dp[to][1 - i][j])) % mod;
					}
					
					dp[v][i][j] = (dp[v][i][j] + mod - c) % mod;
				}
				else
				{
					for (int iter = 0; iter < 2; iter++)
					{
						ll a[] = { i, 1 - i };
						
						for (int h = 0; h < g[v].size(); h++)
						{
							int to = g[v][h];
							if (iter == 1)
								to = g[v][g[v].size() - 1 - h];
							
							ll x = ((dp[to][0][0] * a[0]) % mod) + ((dp[to][1][0] * a[1]) % mod);
							if (x >= mod)
								x -= mod;
								
							ll y = ((dp[to][1][1] * a[1]) % mod) + ((dp[to][0][1] * a[0]) % mod);
							if (y >= mod)
								y -= mod;
							
							a[0] += x;
							if (a[0] >= mod)
								a[0] -= mod;
							a[1] += y;
							if (a[1] >= mod)
								a[1] -= mod;
						}
						
						dp[v][i][j] += a[j];
						if (dp[v][i][j] >= mod)
							dp[v][i][j] -= mod;
					}
					
					for (int iter = 0; iter < 1; iter++)
					{
						ll a[] = { i, 1 - i };
						
						for (int h = 0; h < g[v].size(); h++)
						{
							int to = g[v][h];
							if (iter == 1)
								to = g[v][g[v].size() - 1 - h];
							
							ll x = ((dp[to][1][0] * a[1]) % mod);
							
							
							
							if (x >= mod)
								x -= mod;
								
							ll y = ((dp[to][0][1] * a[0]) % mod);
							
							
							if (y >= mod)
								y -= mod;
							
							
							a[0] += x;
							if (a[0] >= mod)
								a[0] -= mod;
							
							a[1] += y;
							if (a[1] >= mod)
								a[1] -= mod;
						}
						
						dp[v][i][j] += (mod - a[j]);
						if (dp[v][i][j] >= mod)
							dp[v][i][j] -= mod;
					}
				}
				
				
				
			}
		}
	}
	else
	{
		dp[v][1][0] = dp[v][0][1] = 1;
	}
}


int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		g[x].pb(i);
	}
	
	dfs(1, -1);
	
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
				cout << dp[i][j][k] << " ";
			cout << endl;
		}	
	}*/
			
	
	cout << (dp[1][0][0] + dp[1][0][1]) % mod << endl;
	
	return 0;
}