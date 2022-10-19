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


const int N = 2e6 + 30;
int mod = 600;

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

int n, m, sm;
int a[N], pat1[N], pat2[N], haj[N], aj[N];
bool col[N];
int t[4 * N];
int flag[4 * N];
void push(int nd)
{
	t[nd] += flag[nd];
	flag[nd * 2] += flag[nd];
	flag[nd * 2 + 1] += flag[nd];
	flag[nd] = 0;
}
void upd(int ql, int qr, int val, int nl = 0, int nr = m, int nd = 1)
{
	push(nd);
	if (ql > nr || qr < nl) return;
	if (ql == nl && qr == nr)
	{
		flag[nd] += val;
		push(nd);
		return;
	}
	int mid = (nl + nr) / 2;
	upd(ql, min(mid, qr), val, nl, mid, nd * 2);
	upd(max(mid + 1, ql), qr, val, mid + 1, nr, nd * 2 + 1);
}
int qry(int q, int nl = 0, int nr = m, int nd = 1)
{
	push(nd);
	if (q < nl || q > nr) return 0;
	if (nl == nr)
		return t[nd];
	int mid = (nl + nr) / 2;
	return qry(q, nl, mid, nd * 2) + qry(q, mid + 1, nr, nd * 2 + 1);
}
int t1[4 * N], flag1[4 * N];
void push1(int nd)
{
	t1[nd] += flag1[nd];
	flag1[nd * 2] += flag1[nd];
	flag1[nd * 2 + 1] += flag1[nd];
	flag1[nd] = 0;
}
void upd1(int ql, int qr, int val, int nl = 1, int nr = n, int nd = 1)
{
	push1(nd);
	if (ql > nr || qr < nl) return;
	if (ql == nl && qr == nr)
	{
		flag1[nd] += val;
		push1(nd);
		return;
	}
	int mid = (nl + nr) / 2;
	upd1(ql, min(mid, qr), val, nl, mid, nd * 2);
	upd1(max(mid + 1, ql), qr, val, mid + 1, nr, nd * 2 + 1);
}
int qry1(int q, int nl = 1, int nr = n, int nd = 1)
{
	push1(nd);
	if (q < nl || q > nr) return 0;
	if (nl == nr) return t1[nd];
	int mid = (nl + nr) / 2;
	return qry1(q, nl, mid, nd * 2) + qry1(q, mid + 1, nr, nd * 2 + 1);
}
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		if (!col[a[i]]) upd(i, m, 1);
		col[a[i]] = true;
	}
	for (int i = n; i > 0; i--)
	{
		haj[i] = m;
		if (col[i]) pat1[i] = 1;
		else
		{
			pat1[i] = i;
			pat2[i] = n - sm;
			sm++;
		}
	}
	for (int i = m - 1; i >= 0; i--)
	{
		aj[i] = haj[a[i]];
		haj[a[i]] = i;
	}
	memset(col, 0, sizeof(col));
	for (int i = 0; i < m; i++)
	{
		if (!col[a[i]])
		{
			col[a[i]] = true;
			pat2[a[i]] = qry1(a[i]) + a[i];
			upd1(1, a[i], 1);
			//cout << a[i] << pat2[a[i]] << endl;
		}
	}
	//for (int i = 1; i <= n; i++) cout << pat1[i] << " " << pat2[i] << endl;
	for (int i = 0; i < m; i++)
	{
		pat2[a[i]] = max(pat2[a[i]], qry(aj[i]));
		upd(i, aj[i], -1);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << pat1[i] << " " << pat2[i] << "\n";
	}
	return 0;
}