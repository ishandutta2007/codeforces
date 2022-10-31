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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 500005;
const int inf = 1e9;
pair < int, int > t[maxn * 4];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = mp(-inf, -inf);
		return;
	}
	int c = (l + r) >> 1;
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	t[v] = mp(-inf, -inf);
}

void modify(int v, int l, int r, int i, int j, pair < int, int > val)
{
	if (i <= l && r <= j)
	{
		t[v] = max(t[v], val);
		return;
	}
	
	int c = (l + r) >> 1;
	if (i <= c)
		modify(2 * v, l, c, i, j, val);
	if (c < j)
		modify(2 * v + 1, c + 1, r, i, j, val);
}

pair < int, int > get(int v, int l, int r, int i)
{
	if (l == r)
		return t[v];
		
	int c = (l + r) >> 1;
	pair < int, int > res = t[v];
	
	if (i <= c)
		res = max(get(2 * v, l, c, i), res);
	else
		res = max(get(2 * v + 1, c + 1, r, i), res);
	return res;
}


int a[maxn];
pair < int, int > dp[maxn];
int dpLen[maxn];
int dp2[maxn];
int prv[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	build(1, 0, n);
	
	map < int, int > m;
	for (int i = 1; i <= n; i++)
	{
		if (m.find(a[i]) == m.end())
		{
			m[a[i]] = i;
			prv[i] = -1;
		}
		else
		{
			prv[i] = m[a[i]];
			m[a[i]] = i;
		}
	}
	
	map < int, pair < int, int > > g;
	map < int, int > g2;
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = mp(-1, -1);
		dpLen[i] = dpLen[i - 1];
		if (prv[i] != -1)
		{
			pair < int, int > res = get(1, 0, n, prv[i]);
			//cerr << i << " " << res.fst << " " << res.snd << endl;
			if (g.find(a[i]) == g.end())
			{
				g[a[i]] = res;
				g2[a[i]] = prv[i];
			}
			else
			{
				if (g[a[i]] < res)
				{
					g2[a[i]] = prv[i];
					g[a[i]] = res;
				}
			}
			res = g[a[i]];
			
			
			if (res.fst != -inf && dpLen[res.fst - 1] + 1 > dpLen[i])
			{
				dpLen[i] = dpLen[res.fst - 1] + 1;
				dp[i] = res;
				dp2[i] = g2[a[i]];
			}
			
			if (prv[i] + 1 <= i - 1)
				modify(1, 0, n, prv[i] + 1, i - 1, mp(prv[i], i));
				
			if (prv[prv[i]] != -1)
			{
				if (prv[prv[i]] + 1 <= i - 1)
					modify(1, 0, n, prv[prv[i]] + 1, i - 1, mp(prv[prv[i]], i));
			}
				
			res = get(1, 0, n, prv[i]);
			
			if (g.find(a[i]) == g.end())
			{
				g[a[i]] = res;
				g2[a[i]] = prv[i];
			}
			else
			{
				if (g[a[i]] < res)
				{
					g2[a[i]] = prv[i];
					g[a[i]] = res;
				}
			}
			
		}
		
	}
	
	vector < int > ans;
	//cerr << dp[4].fst << " " << dp[4].snd << endl;
	
	for (int i = n; i >= 1; i--)
	{
		if (dp[i].fst == -1)
		{
			continue;
		}
		ans.pb(a[i]);
		ans.pb(a[dp[i].snd]);
		ans.pb(a[dp2[i]]);
		ans.pb(a[dp[i].fst]);
		i = dp[i].fst;
	}
	
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	
	return 0;
}