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


const int N = 2e6 + 30;
const lli mod = 1e8 + 7;
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


int n, pat = mod;
int a[N], d[N];
vector <int> g[N];
bool col[N], bl, cl[N];
int pr[N];
vector <int> sm1;
void bfs(int v)
{
	d[v] = 0;
	queue <int> q;
	int p;
	q.push(v);
	col[v] = true;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (auto u : g[p])
		{
			if (u == pr[p]) continue;
			if (!col[u])
			{
				d[u] = d[p] + 1;
				col[u] = true;
				pr[u] = p;
				q.push(u);
			}
			else
			{
				pat = min(pat, d[p] + d[u] + 1);
			}
		}
	}
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int sm = a[i];
		vector<int> fp;
		for (int i = 2; i * i <= sm; i++)
		{
			if (sm % i == 0)
			{
				int ss = 0;
				while (sm % i == 0) sm /= i, ss++;
				if (ss % 2 == 1) fp.PB(i);
			}
		}
		if (sm > 1) fp.PB(sm);
		if (fp.size() == 0)
		{
			cout << 1 << endl;
			return 0;
		}
		else if (fp.size() == 1)
		{
			if (!col[fp[0]])
			{
				g[1].PB(fp[0]);
				if (!cl[1]) sm1.PB(1), cl[1] = true;
				g[fp[0]].PB(1);
				if (!cl[fp[0]]) sm1.PB(fp[0]), cl[fp[0]] = true;
				col[fp[0]] = true;
			}
			else
			{
				bl = true;
			}
		}
		else
		{
			int a = fp[0], b = fp[1];
			if (!col[a * b])
			{
				g[a].PB(b);
				if (!cl[a]) sm1.PB(a), cl[a] = true;
				g[b].PB(a);
				if (!cl[b]) sm1.PB(b), cl[b] = true;
				col[a * b] = true;
			}
			else
			{
				bl = true;
			}
		}
	}
	if (bl)
	{
		cout << 2;
		return 0;
	}
	sort(all(sm1));
	for(auto i : sm1)
	{
		if (i > 1000) break;
		memset(d, 0, sizeof(d));
		memset(col, 0, sizeof(col));
		memset(pr, 0, sizeof(pr));
		bfs(i);
	}
	if (pat == mod) cout << -1 << endl;
	else cout << pat << endl;
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