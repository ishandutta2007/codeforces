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

const int maxn = 100005;


pair < int, int > t[4 * maxn];
ll ts[4 * maxn];
int a[maxn];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = mp(a[l], l);
		ts[v] = a[l];
		return;
	}
	
	int c = (l + r) >> 1;
	
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	
	t[v] = max(t[2 * v], t[2 * v + 1]);
	ts[v] = ts[2 * v] + ts[2 * v + 1];
}

void modify(int v, int l, int r, int i, int val)
{
	if (l == r)
	{
		t[v] = mp(val, l);
		ts[v] = val;
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		modify(2 * v, l, c, i, val);
	else
		modify(2 * v + 1, c + 1, r, i, val);
		
	t[v] = max(t[2 * v], t[2 * v + 1]);
	ts[v] = ts[2 * v] + ts[2 * v + 1];
}

ll sum(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
	{
		return ts[v];
	}
	
	int c = (l + r) >> 1;
	
	ll res = 0;
	
	if (i <= c)
		res += sum(2 * v, l, c, i, j);
	if (c < j)
		res += sum(2 * v + 1, c + 1, r, i, j);
		
	return res;
}

pair < int, int > getMax(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
	{
		return t[v];
	}
	
	int c = (l + r) >> 1;
	pair < int, int > res = mp(-1e9, -1e9);
	
	if (i <= c)
		res = max(res, getMax(2 * v, l, c, i, j));
	if (c < j)
		res = max(res, getMax(2 * v + 1, c + 1, r, i, j));
		
	return res;
}

int main(int argc, char *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	build(1, 1, n);
	
	for (int i = 0; i < m; i++)
	{
		int type;
		scanf("%d", &type);
		
		if (type == 1)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			cout << sum(1, 1, n, l, r) << endl;
		}
		else if (type == 2)
		{
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			
			while (true)
			{
				pair < int, int > mm = getMax(1, 1, n, l, r);
				
				if (mm.fst < x)
					break;
				modify(1, 1, n, mm.snd, mm.fst % x);
			}
		}
		else
		{
			int k, x;
			scanf("%d %d", &k, &x);
			
			modify(1, 1, n, k, x);
		}
	}
		
	return 0;
}