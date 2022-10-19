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
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 2e5 + 30;
const lli mod = 998244353;

lli bp(lli a, lli b = mod - 2LL)
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
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n, t;
vector <pair<int, lli> > g[N];
int chp[N];
lli pat, ans;
void dfs0(int v, int par)
{
	chp[v] = 1;
	for (auto p : g[v])
	{
		if (p.fr == par) continue;
		dfs0(p.fr, v);
		chp[v] += chp[p.fr];
	}
}
void dfs(int v, int par)
{
	for (auto p : g[v])
	{
		if (p.fr == par) continue;
		if (chp[p.fr] % 2) pat += p.sc;
		ans += min(chp[p.fr], n - chp[p.fr]) * 1LL * p.sc;
		dfs(p.fr, v);
	}
}
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		pat = 0, ans = 0;
		cin >> n;
		n *= 2;
		for (int i = 0; i < n - 1; i++)
		{
			int a, b;
			lli c;
			cin >> a >> b >> c;
			g[a].PB(MP(b, c));
			g[b].PB(MP(a, c));
		}
		dfs0(1, -1);
		dfs(1, -1);
		cout << pat << " " << ans << endl;
		for (int i = 1; i <= n; i++) g[i].clear();
	}
	return 0;
}