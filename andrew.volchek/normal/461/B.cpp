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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;
const ll mod = 1000000007;
vector < int > g[maxn];
int c[maxn];
ll dp[maxn][2];
ll s[maxn];

ll bpow(ll x, ll n)
{
	ll res = 1;
	x %= mod;
	while (n)
	{
		if (n & 1)
		{
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

void dfs(int v, int p)
{
	bool any = false;
	for (int to : g[v])
		any |= to != p;
		
	if (!any)
	{
		dp[v][c[v]] = 1;
		return;
	}
	
	
	for (int to : g[v])
	{
		if (to != p)
			dfs(to, v);
	}
		
	if (c[v])
	{
		ll curr = 1;
		for (int to : g[v])
		{
			if (to != p)
				curr = (curr * (dp[to][0] + dp[to][1])) % mod; 
		}
		dp[v][1] = curr;
		dp[v][0] = 0;
	}
	else
	{
		ll curr = 1;
		for (int to : g[v])
		{
			if (to == p)
				continue;
			curr = (curr * (dp[to][0] + dp[to][1])) % mod;
		}
		dp[v][0] = curr;
		ll curr2 = 1;
		
		s[0] = 1;
		int pp = 1;
		for (int i = g[v].size() - 1; i >= 0; i--)
		{
			int to = g[v][i];
			if (to == p)
				continue;
			s[pp] = (s[pp - 1] *  (dp[to][0] + dp[to][1])) % mod;
			pp++;
		}
		pp--;
		for (int to : g[v])
		{
			if (to == p)
				continue;
			pp--;
			dp[v][1] = (dp[v][1] + (((s[pp] * curr2) % mod) * dp[to][1])) % mod;
			curr2 = (curr2 * (dp[to][0] + dp[to][1])) % mod;
		}
	}
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int x;
		scanf("%d", &x);
		g[x].pb(i + 1);
		g[i + 1].pb(x);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", c + i);
	for (int i = 0; i < n; i++)
	{
		if (c[i])
		{
			dfs(i, -1);
			cout << dp[i][1] << endl;;
			
			break;
		}
	}
	
	return 0;
}