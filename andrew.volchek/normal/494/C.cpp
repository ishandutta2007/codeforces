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

const int maxn = 100005;

int a[maxn];
int t[4 * maxn];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = a[l];
		return;
	}
	int c = (l + r) >> 1;
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
		return t[v];
	int res = 0;
	int c = (l + r) >> 1;
	if (i <= c)
		res = max(res, get(2 * v, l, c, i, j));
	if (c < j)
		res = max(res, get(2 * v + 1, c + 1, r, i, j));
	return res;
}

vector < int > g[maxn];

int lb[maxn], rb[maxn];
double pr[maxn];

vector < pair < int, ld > > merge(vector < pair < int, ld > > &a, vector < pair < int, ld > > &b)
{
	vector < ld > sa(a.size()), sb(b.size());
	
	sa[0] = a[0].snd;
	sb[0] = b[0].snd;
	
	for (int i = 1; i < a.size(); i++)
		sa[i] = sa[i - 1] + a[i].snd;
		
	for (int i = 1; i < b.size(); i++)
		sb[i] = sb[i - 1] + b[i].snd;
		
	vector < pair < int, ld > > res(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
	auto it = unique(res.begin(), res.end(), [](const pair < int, ld > &x, const pair < int, ld > &y) { return x.fst == y.fst; });
	res.resize(it - res.begin());
	
	auto it1 = a.begin(), it2 = b.begin();
	
	for (auto &item : res)
	{
		while (it1 != a.end() && it1->fst < item.fst) it1++;
		while (it2 != b.end() && it2->fst < item.fst) it2++;
		
		ld x = 0;
		
		if (it1 != a.end() && it1->fst == item.fst)
			x += it1->snd * (it2 == b.begin() ? 0 : sb[it2 - b.begin() - 1]);
			
		if (it2 != b.end() && it2->fst == item.fst)
			x += it2->snd * (it1 == a.begin() ? 0 : sa[it1 - a.begin() - 1]);
			
		if (it1 != a.end() && it2 != b.end() && it1->fst == item.fst && it2->fst == item.fst)
			x += it1->snd * it2->snd;
			
		item.snd = x;
	}
	
	reverse(res.begin(), res.end());
	//res.resize(min(5005, (int)res.size()));
	int m = res[0].fst;
	while (res.back().fst < m - 5005) res.pop_back();
	reverse(res.begin(), res.end());
	
	return res;
}

int n;

vector < pair < int, ld > > dfs(int v, int p)
{
	vector < pair < int, ld > > res;
	
	if (v)
		res.pb(mp(get(1, 1, n, lb[v], rb[v]), 1.0));
	else
		res.pb(mp(get(1, 1, n, 1, n), 1));
	
	for (int to : g[v])
	{
		if (to == p)
			continue;
			
		auto c = dfs(to, v);
		
		res = merge(res, c);
	}
	
	vector < pair < int, ld > > nres, fres;
	
	for (auto &x : res)
	{
		nres.pb(mp(x.fst + 1, x.snd * pr[v]));
		x.snd *= 1.0 - pr[v];
	}
	
	fres.resize(nres.size() + res.size());
	
	merge(res.begin(), res.end(), nres.begin(), nres.end(), fres.begin());
	
	int s = 0;
	
	for (int i = 0; i < fres.size(); i++)
	{
		int j = i;
		ld x = 0.0;
		while (j < fres.size() && fres[j].fst == fres[i].fst)
		{ 
			x += fres[j].snd;
			j++;
		}
		
		fres[s++] = mp(fres[i].fst, x);
		
		i = j - 1;	
	}
	
	fres.resize(s);
	
	reverse(fres.begin(), fres.end());
	//fres.resize(min(5005, (int)fres.size()));
	int m = fres[0].fst;
	while (fres.back().fst < m - 5005) fres.pop_back();
	reverse(fres.begin(), fres.end());
	
	return fres;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int q;
	scanf("%d %d", &n, &q);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	build(1, 1, n);
	
	vector < pair < pair < int, int >, pair < int, int > > > e;
	
	for (int i = 1; i <= q; i++)
	{
		scanf("%d %d %lf", lb + i, rb + i, pr + i);
		e.pb(mp(mp(lb[i], -rb[i]), mp(0, i)));
		e.pb(mp(mp(rb[i], (int)1e9), mp(1, i)));
	}
	
	sort(e.begin(), e.end());
	
	vector < int > st;
	st.pb(0);
	
	for (auto x : e)
	{
		if (!x.snd.fst)
		{
			g[st.back()].pb(x.snd.snd);
			st.pb(x.snd.snd);
		}
		else
		{
			st.pop_back();
		}
	}
	
	auto res = dfs(0, -1);
	
	ld ans = 0;
	
	for (auto x : res)
	{
		ans += x.snd * x.fst;
	}
		
	cout.precision(10);
	cout << fixed << ans << endl;
	
	return 0;
}