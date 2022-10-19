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


const lli N = 2e5 + 500;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 150;

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

int n, m, k, pat;
int a[N], b[N], c[N];
bool cl[N], col[N], ss[N];
vector <int> g[N];
pair <int, int> fp[N];
int main()
{
	fastio;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
		cl[c[i]] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].PB(b);
		g[b].PB(a);
	}
	queue<pair<int, int> > q;
	pair <int, int> sm;
	q.push(MP(1, 0));
	col[1] = true;
	while (!q.empty())
	{
		sm = q.front();
		q.pop();
		a[sm.fr] = sm.sc;
		for (auto p : g[sm.fr])
		{
			if (!col[p])
			{
				col[p] = true;
				q.push(MP(p, sm.sc + 1));
			}
		}
	}
	for (int i = 1; i <= n; i++) col[i] = false;
	q.push(MP(n, 0));
	col[n] = true;
	while (!q.empty())
	{
		sm = q.front();
		q.pop();
		b[sm.fr] = sm.sc;
		for (auto p : g[sm.fr])
		{
			if (!col[p])
			{
				col[p] = true;
				q.push(MP(p, sm.sc + 1));
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		fp[i] = MP(a[c[i]] - b[c[i]], c[i]);
	}
	sort(fp, fp + k);
	int mx = -mod;
	for (int i = k - 1; i >= 0; i--)
	{
		pat = max(pat, a[fp[i].sc] + mx + 1);
		mx = max(mx, b[fp[i].sc]);
		//cout << mx << endl;
	}
	//cout << fp[0].sc << " " << fp[1].sc << endl;
	mx = -mod;
	for (int i = 0; i < k; i++)
	{
		pat = max(pat, b[fp[i].sc] + mx + 1);
		mx = max(mx, a[fp[i].sc]);
	}
	cout << min(pat, a[n]) << endl;
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