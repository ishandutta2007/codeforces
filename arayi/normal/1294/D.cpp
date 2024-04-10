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
int q, x;
int t[4 * N];
void upd(int q, int nl = 0, int nr = x - 1, int nd = 1)
{
	if (q < nl || q > nr) return;
	if (nl == nr)
	{
		t[nd]++;
		return;
	}
	int mid = (nl + nr) / 2;
	upd(q, nl, mid, nd * 2);
	upd(q, mid + 1, nr, nd * 2 + 1);
	t[nd] = min(t[nd * 2], t[nd * 2 + 1]);
}
int qry(int ql, int qr, int nl = 0, int nr = x - 1, int nd = 1)
{
	if (ql > nr || qr < nl) return INT_MAX;
	if (ql == nl && qr == nr)
	{
		return t[nd];
	}
	int mid = (nl + nr) / 2;
	return min(qry(ql, min(mid, qr), nl, mid, nd * 2), 
		qry(max(mid + 1, ql), qr, mid + 1, nr, nd * 2 + 1));
}
int main()
{
	fastio;
	cin >> q >> x;
	for (int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		upd(a % x);
		int l = 0, r = x - 1, ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (qry(l, mid) == t[1])
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << x * t[1] + ans << endl;
	}
	return 0;
}