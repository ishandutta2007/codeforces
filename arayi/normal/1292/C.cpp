#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define pir pair<int, int>
#define itn int
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 3030;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 4e5;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int n;
vector <int> g[N];
lli dp[N][N], chp[N][N], fp[N][N];
vector <pir> a[N][N];
vector <int> pr;
int rt;
void dfs(int v, int par, int xr)
{
	a[rt][xr].PB(MP(par, v));
	chp[rt][v] = 1;
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs(p, v, xr + 1);
		chp[rt][v] += chp[rt][p];
	}
}
void dfs1(int v, int par)
{
	pr.PB(v);
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs1(p, v);
	}
	if (pr.size() > 1) fp[rt][v] = chp[rt][v] * (n - chp[rt][pr[1]]);
	pr.pop_back();
}
lli pat;
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	for (int i = 1; i <= n; i++)
	{
		rt = i;
		dfs(i, -1, 0);
		dfs1(i, -1);
	}
	/*for (int i = 1; i <= n; i++)
	{
		cout << i << "-";
		for (int j = 1; j <= n; j++)
		{
			cout << fp[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 1; i <= n; i++)
	{
		//cout << i << "-";
		for (int j = 1; j <= n; j++)
		{
			for (auto p : a[j][i])
			{
				//cout << p.fr << p.sc << " ";
				dp[j][p.sc] = max(dp[j][p.sc], dp[j][p.fr] + fp[j][p.sc]);
				dp[j][p.sc] = max(dp[p.sc][j], dp[j][p.sc]);
				dp[p.sc][j] = max(dp[p.sc][j], dp[j][p.sc]);
				pat = max(pat, dp[j][p.sc]);
			}
		}
		//cout << endl;
	}
	//cout << dp[1][5] << endl;
	cout << pat << endl;
	return 0;
}