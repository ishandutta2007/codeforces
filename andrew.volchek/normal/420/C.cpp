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

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 300005;

pair < int, int > a[maxn];
vector < int > b[maxn];
int deg[maxn];

int tree[maxn];

void modify(int i, int val)
{
	while (i < maxn)
	{
		tree[i] += val;
		i = i | (i + 1);
	}
}

int sum(int r)
{
	int res = 0;
	while (r >= 0)
	{
		res += tree[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n, p;
	scanf("%d %d", &n, &p);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i].fst, &a[i].snd);
		b[a[i].fst].pb(i);
		b[a[i].snd].pb(i);
	}
	
	for (int i = 1; i <= n; i++)
	{
		deg[i] = b[i].size();
		modify(deg[i], 1);
	}
	
	ll ans = 0;
	
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			int u = a[b[i][j]].fst;
			if (u == i)
				u = a[b[i][j]].snd;
				
			modify(deg[u], -1);
			modify(deg[u] - 1, +1);
			deg[u]--;
		}
		
		modify(deg[i], -1);
		
		ans += n - 1 - sum(p - deg[i] - 1);
		
		modify(deg[i], +1);
		
		for (int j = 0; j < b[i].size(); j++)
		{
			int u = a[b[i][j]].fst;
			if (u == i)
				u = a[b[i][j]].snd;
				
			modify(deg[u], -1);
			modify(deg[u] + 1, +1);
			deg[u]++;
		}
	}
	
	cout << ans / 2 << endl;
	

	return 0;
}