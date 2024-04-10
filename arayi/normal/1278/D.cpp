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
int a[N];
vector <int> g[N];
int sm;
bool col[N];
vector <int> t[4 * N], ret;
pair <int, int> b[N];
void upd(int q, int nl = 1, int nr = 2 * n, int nd = 1)
{
	if (q < nl || q > nr) return;
	t[nd].PB(a[q]);
	if (nl == nr) return;
	int mid = (nl + nr) / 2;
	upd(q, nl, mid, nd * 2);
	upd(q, mid + 1, nr, nd * 2 + 1);
}
void qry(int ql, int qr, int nl = 1, int nr = 2 * n, int nd = 1)
{
	if (ql > nr || qr < nl) return;
	if (ql == nl && qr == nr)
	{
		for (auto p : t[nd]) ret.PB(p);
		return;
	}
	int mid = (nl + nr) / 2;
	qry(ql, min(mid, qr), nl, mid, nd * 2);
	qry(max(mid + 1, ql), qr, mid + 1, nr, nd * 2 + 1);
}
void dfs(int v)
{
	col[v] = true;
	for (auto p : g[v])
	{
		if (col[p]) continue;
		dfs(p);
	}
}
bool stg()
{
	for (int i = 1; i <= n; i++)
	{
		if (!col[i]) return false;
	}
	return true;
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		b[i] = MP(l, r);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		// << b[i].fr << " " << b[i].sc << endl;
		qry(b[i].fr, b[i].sc);
		for (auto p : ret)
		{
			g[i + 1].PB(p);
			g[p].PB(i + 1);
			//cout << p << " " << i + 1 << endl;
			sm++;
			if (sm >= n)
			{
				cout << "NO";
				return 0;
			}
		}
		ret.clear();
		a[b[i].sc] = i + 1;
		upd(b[i].sc);
	}
	if (sm != n - 1)
	{
		cout << "NO";
		return 0;
	}
	dfs(1);
	if (stg())
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}