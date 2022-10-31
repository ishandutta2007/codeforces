#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <vector>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define y1 asdkjghjasd
#define fst first
#define snd second
#define y0 sakjglajaa
#define ll long long
#define ull unsigned long long
#define ld long double

const int maxn = 500005;
const int inf = 1e9;

int t[4 * maxn];

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
		
	t[v] = min(t[2 * v], t[2 * v + 1]);
}


int a[maxn];
int nxt[maxn];
int ans[maxn];
vector < pair < int, int > > q[maxn];

int main()
{
	//freopen("a.in", "r", stdin);
	
	for (int i = 0; i < maxn * 4; i++)
		t[i] = inf;
		
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	map < int, int > was;
	for (int i = n; i >= 1; i--)
	{
		if (was.find(a[i]) == was.end())
			nxt[i] = -1;
		else
			nxt[i] = was[a[i]];
		was[a[i]] = i;
	}
	
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		q[l].pb(mp(r, i));
	}
	
	for (int i = n; i >= 1; i--)
	{
		if (nxt[i] != -1)
		{
			modify(1, 0, maxn - 1, nxt[i], nxt[i] - i);
		}
		
		for (auto x : q[i])
		{
			int res = get(1, 0, maxn - 1, i, x.fst);
			if (res == inf)
				ans[x.snd] = -1;
			else
				ans[x.snd] = res;
		}
	}
	
	for (int i = 0; i < m; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}