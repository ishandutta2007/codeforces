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
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };


const int N = 2e5 + 20;
lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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
ostream& operator<<(ostream& c, pir a)
{
	c << a.fr << " " << a.sc;
	return c;
}


int n;
vector <int> g[N];
bool col[N];
int xr[N];
int sm1 = 1, sm2, qn, qn1;
void dfs(int v, int par)
{
	xr[v] = 0;
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs(p, v);
		xr[v] = xr[p] ^ 1;
	}
	for (auto p : g[v])
	{
		if (p == par) continue;
		if (xr[v] == xr[p]) sm1 = 3;
	}
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].ad(b);
		g[b].ad(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (g[i].size() > 1)
		{
			dfs(i, -1);
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (g[i].size() == 1)
		{
			qn++;
			if (!col[g[i][0]]) qn1++, col[g[i][0]] = true;
		}
	}
	cout << sm1 << " ";
	cout << (n - qn - 1) + qn1 << endl;
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