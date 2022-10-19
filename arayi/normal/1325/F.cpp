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


int n, m, sq;
vector <int> g[N];
int d[N], pr[N];
int col[N];
bool cl[N];
void dfs(int v)
{
	col[v] = 1;
	for (auto p : g[v])
	{
		if (p == pr[v] || col[p] == 2) continue;
		if (col[p])
		{
			if (d[v] - d[p] >= sq - 1)
			{
				cout << 2 << endl;
				vector <int> ans;
				ans.PB(v);
				do
				{
					v = pr[v];
					ans.PB(v);
				} while (v != p);
				cout << ans.size() << endl;
				for (auto p : ans) cout << p << " ";
				exit(0);
			}
			continue;
		}
		pr[p] = v;
		d[p] = d[v] + 1;
		dfs(p);
	}
	col[v] = 2;
	if (!cl[v])
	{
		for (auto p : g[v]) cl[p] = true;
	}
}
int main()
{
	fastio;
	cin >> n >> m;
	sq = (sqrt(n - 1) + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	dfs(1);
	cout << 1 << "\n";
	for (int i = 1; sq; i++)
	{
		if (!cl[i]) cout << i << " ", sq--;
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