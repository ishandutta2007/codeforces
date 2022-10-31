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
#define y1 _y1
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
const int inf = 1e9;

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
		t[v] = val;
		return;
	}
	
	int c = (l + r) >> 1;
	
	if (i <= c)
		modify(2 * v, l, c, i, val);
	else
		modify(2 * v + 1, c + 1, r, i, val);
		
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

int good[maxn];

struct q
{
	int x1, y1, x2, y2, idx;
	q(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0, int _idx = 0)
		:x1(_x1), y1(_y1), x2(_x2), y2(_y2), idx(_idx)
	{
	}
	
	bool operator < (const q &x) const
	{
		return y1 < x.y1;
	}
};

void solve(vector < q > qq, vector < pair < int, int > > p)
{
	sort(qq.begin(), qq.end());
	
	sort(p.begin(), p.end(), [](const pair < int, int > &i, const pair < int, int > &j)
	{
		return i.snd < j.snd;
	});
	
	int pr = ((int)p.size()) - 1;
	
	build(1, 0, maxn - 1);
	
	for (int i = qq.size() - 1; i >= 0; i--)
	{
		while (pr >= 0 && p[pr].snd >= qq[i].y1)
		{
			modify(1, 0, maxn - 1, p[pr].fst, p[pr].snd);
			pr--;
		}
		
		int res = get(1, 0, maxn - 1, qq[i].x1, qq[i].x2);
		
		if (res > qq[i].y2)
			good[qq[i].idx]--;
	}
}



int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n, m, k, g;
	scanf("%d %d %d %d", &n, &m, &k, &g);
	
	vector < pair < int, int > > p;
	
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		p.emplace_back(x, y);
	}
	
	vector < q > qq;
	for (int i = 0; i < g; i++)
	{
		good[i] = 2;
		
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		qq.emplace_back(x1, y1, x2, y2, i);
	}
	
	solve(qq, p);
	
	for (auto &x : qq)
	{
		swap(x.x1, x.y1);
		swap(x.x2, x.y2);
	}
	
	for (auto &x : p)
		swap(x.fst, x.snd);
		
	solve(qq, p);
	
	for (int i = 0; i < g; i++)
	{
		if (good[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	
	
	return 0;
}