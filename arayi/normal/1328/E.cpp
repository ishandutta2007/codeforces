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
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 2e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
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

int n, m;
int tin[N], tout[N], ti, p[N], xr[N];
vector <int> g[N];
void dfs(int v, int par)
{
	tin[v] = ti++;
	p[v] = par;
	for (auto p : g[v])
	{
		if (p == par) continue;
		xr[p] = xr[v] + 1;
		dfs(p, v);
	}
	tout[v] = ti++;
}
bool f(int a, int b)
{
	return (tin[a] <= tin[b] && tout[a] >= tout[b]);
}
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		int mx = 0, u = 0;
		vector<int> sm;
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			sm.push_back(x);
			if (xr[x] >= mx)
			{
				mx = xr[x];
				u = x;
			}
		}
		bool bl = true;
		for (auto p1 : sm)
		{
			if (f(p1, u) || f(p[p1], u)) continue;
			bl = false;
		}
		if (bl) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}


/*
  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/