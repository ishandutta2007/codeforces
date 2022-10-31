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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 100005;
const int inf = 1e9;

int a[maxn];

int lc, sc, n;

int r[maxn];

int t[maxn * 4];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = inf;
		return;
	}
	int c = (l + r) >> 1;
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	t[v] = inf;
}

void modify(int v, int l, int r, int i, int val)
{
	if (l == r)
	{
		t[v] = min(t[v], val);
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		modify(2 * v, l, c, i, val);
	else
		modify(2 * v + 1, c + 1, r, i, val);
		
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
		return t[v];
	int res = inf;
	int c = (l + r) >> 1;
	if (i <= c)
		res = min(res, get(2 * v, l, c, i, j));
	if (c < j)
		res = min(res, get(2 * v + 1, c + 1, r, i, j));
	return res;
}

int dp[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	scanf("%d %d %d", &n, &sc, &lc);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	multiset < int > s;
	
	int l = 1;
	
	for (int i = 1; i <= n; i++)
	{
		l = min(l, i);
		s.insert(a[i]);
		
		while (!s.empty() && ((*s.rbegin()) - (*s.begin()) > sc))
		{
			s.erase(s.find(a[l]));
			l++;
		}
		
		if (i - l + 1 >= lc)
			r[i] = l;
		else
			r[i] = inf;
	}
	
	build(1, 0, maxn - 1);
	
	modify(1, 0, maxn - 1, 0, 0);
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = inf;
		
		if (r[i] == inf)
			continue;
		
		int res = get(1, 0, maxn - 1, r[i] - 1, i - lc);
		dp[i] = min(inf, res + 1);
		modify(1, 0, maxn - 1, i, dp[i]);
	}
	
	//for (int i = 1; i <= n; i++)
	//	cerr << dp[i] << " " ;
	//cerr << endl;
	
	if (dp[n] == inf)
		cout << -1;
	else
		cout << dp[n];

	return 0;
}