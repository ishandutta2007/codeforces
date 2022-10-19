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
const lli mod = 1e9 + 7;
int q, n, m;
int a[N];
pair <int, int> b[N];
int t[4 * N], t1[4 * N];
void bld(int nl = 0, int nr = n - 1, int nd = 1)
{
	if (nl == nr)
	{
		t[nd] = a[nl];
		return;
	}
	int mid = (nl + nr) / 2;
	bld(nl, mid, nd * 2);
	bld(mid + 1, nr, nd * 2 + 1);
	t[nd] = max(t[nd * 2 + 1], t[nd * 2]);
}
void bld1(int nl = 0, int nr = m - 1, int nd = 1)
{
	if (nl == nr)
	{
		t1[nd] = b[nl].sc;
		return;
	}
	int mid = (nl + nr) / 2;
	bld1(nl, mid, nd * 2);
	bld1(mid + 1, nr, nd * 2 + 1);
	t1[nd] = max(t1[nd * 2 + 1], t1[nd * 2]);
}
int qry(int ql, int qr, int nl = 0, int nr = n - 1, int nd = 1)
{
	if (ql > nr || qr < nl) return 0;
	if (ql == nl && qr == nr)
	{
		return t[nd];
	}
	int mid = (nl + nr) / 2;
	return max(qry(ql, min(mid, qr), nl, mid, nd * 2), qry(max(mid + 1, ql), qr, mid + 1, nr, nd * 2 + 1));
}
int qry1(int ql, int qr, int nl = 0, int nr = m - 1, int nd = 1)
{
	if (ql > nr || qr < nl) return 0;
	if (ql == nl && qr == nr)
	{
		return t1[nd];
	}
	int mid = (nl + nr) / 2;
	return max(qry1(ql, min(mid, qr), nl, mid, nd * 2), qry1(max(mid + 1, ql), qr, mid + 1, nr, nd * 2 + 1));
}
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> n;
		int mx = 0;
		for (int i = 0; i < n; i++) cin >> a[i], mx = max(a[i], mx);
		bld();
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> b[i].sc >> b[i].fr;
		}
		sort(b, b + m);
		bld1();
		//cout << t1[1] << endl;
		if (mx > qry1(0, m - 1))
		{
			cout << -1 << endl;
			continue;
		}
		// cout << upper_bound(b, b + m, MP(1, 0)) - b << endl;
		int i1 = 0, pat = 0;
		while (i1 < n)
		{
			pat++;
			int l = i1, r = min(n - 1, i1 + b[m - 1].fr - 1), ans = i1;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				int ii = upper_bound(b, b + m, MP(mid - i1 + 1, 0)) - b;
				//cout << ii << endl;
				if (qry(i1, mid) > qry1(ii, m - 1))
				{
					r = mid - 1;
				}
				else
				{
					ans = mid;
					l = mid + 1;
				}
			}
			i1 = ans + 1;
		}
		cout << pat << endl;
	}
	return 0;
}