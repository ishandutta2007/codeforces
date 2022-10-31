#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 200005;

ll t[4 * maxn];

ll get(int v, int l, int r, int i, int j)
{
	if (i > j)
		return -1;
		
	if (i <= l && r <= j)
		return t[v];
		
	ll res = 0;
	int c = (l + r) >> 1;
	
	if (i <= c)
		res = max(res, get(2 * v, l, c, i, j));
	if (c < j)
		res = max(res, get(2 * v + 1, c + 1, r, i, j));
	return res;
}

void modify(int v, int l, int r, int i, ll val)
{
	if (l == r)
	{
		t[v] = max(t[v], val);
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		modify(2 * v, l, c, i, val);
	else
		modify(2 * v + 1, c + 1, r, i, val);
		
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

ll p[maxn];
ll h[maxn];

pair < ll, pair < ll, ll > > dp[maxn][20];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int _x, _y;
		scanf("%d %d", &_x, &_y);
		p[i] = _x;
		h[i] = _y;
	}
	
	p[n] = 1e15;
	
	for (int i = n - 1; i >= 0; i--)
	{
		int lo = i;
		int hi = n;
		while (hi - lo > 1)
		{
			int mid = (lo + hi) >> 1;
			if (p[i] + h[i] >= p[mid])
				lo = mid;
			else
				hi = mid;
		}
		
		
		ll r = max(p[i] + h[i], get(1, 0, n - 1, i, lo));
		modify(1, 0, n - 1, i, r);
		
		lo = i;
		hi = n;
		
		while (hi - lo > 1)
		{
			int mid = (lo + hi) >> 1;
			if (r >= p[mid])
				lo = mid;
			else
				hi = mid;
		}
		
		dp[i][0] = mp(hi, mp(r, 0));
		
		for (int j = 1; j < 20; j++)
		{
			int cr = dp[i][j - 1].fst;
			if (cr == n)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = mp(dp[cr][j - 1].fst, mp(dp[cr][j - 1].snd.fst,
				 dp[cr][j - 1].snd.snd + dp[i][j - 1].snd.snd + p[cr] - dp[i][j - 1].snd.fst));
		}
	}
	
	
	//cout << dp[1][0].fst << " " << dp[1][0].snd.fst << " " << dp[1][0].snd.snd << endl;
	
	int q;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		
		ll ans = 1e18;
		ll add = 0;
		
		for (int j = 19; j >= 0; j--)
		{
			if (dp[x][j].fst > y)
			{
				ans = min(ans, add + dp[x][j].snd.snd);
			}
			else
			{
				int cr = dp[x][j].fst;
				add += dp[x][j].snd.snd + p[cr] - dp[x][j].snd.fst;
				x = cr;
			}
		}
		
		int _ans = ans;
		printf("%d\n", _ans);
	}
	
	
	return 0;
}