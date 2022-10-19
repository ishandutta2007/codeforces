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



const int N = 1e6 + 30;
const ld mod = 1e6;

int n;
vector <int> g[N];
int parr[N], l[N], r[N], R;
void dfs(int v, int par)
{
	if (par)
	{
		l[v] = parr[par] - 1;
		parr[par]--;
		r[v] = R + g[v].size();
		R += g[v].size();
		parr[v] = r[v];
	}
	for (auto p : g[v])
	{
		if (p == par) continue;
		dfs(p, v);
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
		g[a].PB(b);
		g[b].PB(a);
	}
	l[1] = 1;
	r[1] = g[1].size() + 2;
	R = r[1];
	parr[1] = r[1];
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << l[i] << " " << r[i] << endl;
	}
	return 0;
}