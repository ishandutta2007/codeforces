#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second
#define sqr(x) ((int64) x) * (x)

const string name = "d";

int n, q;
map <int, int> M, cnt;
set < pii > seg;
set < pair <int, pii> > len;

int add()
{
	pii now = (*len.begin()).second;
	int l = -now.fs;
	int r = -now.sc;
	len.erase(len.begin());
	seg.erase(mp(l, r));
	
	int pos = (l + r + 1) >> 1;
	if (l <= pos - 1)
	{
		len.insert(mp(l - pos, mp(-l, 1 - pos)));
		seg.insert(mp(l, pos - 1));
	}
	if (pos + 1 <= r)
	{
		len.insert(mp(pos - r, mp(-1 - pos, -r)));
		seg.insert(mp(pos + 1, r));
	}
	return pos;
}

void del(int pos)
{
	pii ll;
	set < pii> :: iterator it = seg.lower_bound(mp(pos, pos));
	if (it != seg.end())
		ll = *seg.lower_bound(mp(pos, pos));
	else
		ll = mp(pos, pos);
	pii rr;
	if (it == seg.begin() || it == seg.end())
		rr = mp(pos, pos);
	else
		rr = *(--it);

	swap(ll, rr);
	int l = pos, r = pos;
	if (ll.sc >= pos - 1)
	{
		l = ll.fs;
		if (ll != mp(pos, pos))
		{
			seg.erase(ll);
			len.erase(mp(ll.fs - ll.sc - 1, mp(-ll.fs, -ll.sc)));
		}
	}
	if (rr.fs <= pos + 1)
	{
		r = rr.sc;
		if (rr != mp(pos, pos))
		{
			seg.erase(rr);
			len.erase(mp(rr.fs - rr.sc - 1, mp(-rr.fs, -rr.sc)));
		}
	}
	seg.insert(mp(l, r));
	len.insert(mp(l - r - 1, mp(-l, -r)));
}

void update(int x, int c)
{
	while (x <= n)
	{
		if (cnt.count(x)) cnt[x] += c;
		else cnt[x] = c;
		x = (x + 1) | x;
	}
}

int get(int x)
{
	int res = 0;
	while (x > 0)
	{
		if (cnt.count(x)) res += cnt[x];
		x = ((x + 1) & x) - 1;
	}
	return res;
}

int main()
{
	//freopen((name + ".in").data(), "r", stdin);
	//freopen((name + ".out").data(), "w", stdout);

	cin >> n >> q;
	cnt.clear();
	seg.clear();
	seg.insert(mp(1, n));
	M.clear();
	len.clear();
	len.insert(mp(-n, mp(-1, -n)));
	seg.insert(mp(n + 2, n + 2));
	forn(i, q)
	{
		int w;
		scanf("%d", &w);
		if (w > 0)
		{
			if (!M.count(w) || M[w] == 0)
			{
				M[w] = add();
				update(M[w], 1);
			}
			else
			{
				del(M[w]);
				update(M[w], -1);
				M[w] = 0;
			}
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", get(r) - get(l - 1));
		}
	}

	return 0;
}