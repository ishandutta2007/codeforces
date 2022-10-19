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
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 4e5 + 20;
const lli mod = 1e9 + 7;

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
int n;
int a[N];
lli pat[N], p[N], mn = LLONG_MAX;
lli t[4 * N], flag[4 * N];
void push(int nd)
{
	t[nd] += flag[nd];
	flag[nd * 2] += flag[nd];
	flag[nd * 2 + 1] += flag[nd];
	flag[nd] = 0;
}
void bld(int nl = 0, int nr = n, int nd = 1)
{
	if (nl == nr)
	{
		t[nd] = pat[nl];
		return;
	}
	int mid = (nl + nr) / 2;
	bld(nl, mid, nd * 2);
	bld(mid + 1, nr, nd * 2 + 1);
	t[nd] = min(t[nd * 2], t[nd * 2 + 1]);
}
void upd(int ql, int qr, lli val, int nl = 0, int nr = n, int nd = 1)
{
	push(nd);
	if (ql > nr || qr < nl) return;
	if (nl == ql && nr == qr)
	{
		flag[nd] += val;
		push(nd);
		return;
	}
	int mid = (nl + nr) / 2;
	upd(ql, min(mid, qr), val, nl, mid, nd * 2);
	upd(max(mid + 1, ql), qr, val, mid + 1, nr, nd * 2 + 1);
	t[nd] = min(t[nd * 2], t[nd * 2 + 1]);
}
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		p[a[i]] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		pat[i] = pat[i - 1] + p[i];
	}
	bld();
	for (int i = 0; i < n - 1; i++)
	{
		upd(a[i], n, -p[a[i]]);
		upd(0, a[i] - 1, p[a[i]]);
		push(1);
		mn = min(mn, t[1]);
	}
	cout << mn << endl;
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