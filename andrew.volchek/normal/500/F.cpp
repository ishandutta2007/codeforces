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

const int maxn = 40505;


int lb[maxn], rb[maxn], cost[maxn], hap[maxn];

vector < int > ev[maxn];

int qcost[maxn];


int ans[maxn];

int dp[4005];
int f[4005];



void update(int w, int c, vector < pair < int, int > > &hist)
{
	for (int i = 0; i < 4005; i++)
	{
		f[i] = dp[i];
		if (i - w >= 0 && dp[i - w] + c > f[i])
		{
			f[i] = dp[i - w] + c;
		//	hist.pb(mp(i, dp[i]));
		}
	}
	
	for (int i = 0; i < 4005; i++)
		dp[i] = f[i];
}

void rollback(vector < pair < int, int > > &hist)
{
	for (int i = int(hist.size()) - 1; i >= 0; i--)
		dp[hist[i].fst] = hist[i].snd;
}


void rec(int l, int r)
{
	if (l == r)
	{
		
		for (int x : ev[l])
		{
			if (x < 0)
			{
				int y = -x;
				ans[y] = dp[qcost[y]];
			}
		}
		
		
		return;
	}
	
	int c = (l + r) >> 1;
	
	vector < pair < int, int > > hist;
	vector < int > was(4005);
	
	for (int i = 0; i < 4005; i++)
		was[i] = dp[i];
	
	for (int i = c + 1; i <= r; i++)
	{
		for (int x : ev[i])
		{
			if (x > 0)
			{
				if (lb[x] < l)
				{
					update(cost[x], hap[x], hist);
				}
			}
		}
	}
	
	rec(l, c);
	
	//rollback(hist);
	//hist.clear();
	
	for (int i = 0; i < 4005; i++)
		dp[i] = was[i];
	
	for (int i = l; i <= c; i++)
	{
		for (int x : ev[i])
		{
			if (x > 0)
			{
				if (rb[x] > r)
				{
					update(cost[x], hap[x], hist);
				}
			}
		}
	}
	
	rec(c + 1, r);
	
	for (int i = 0; i < 4005; i++)
		dp[i] = was[i];
	
//	rollback(hist);
//	hist.clear();
}





int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	int n, p;
	scanf("%d %d", &n, &p);
	
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", cost + i, hap + i, lb + i);
		rb[i] = lb[i] + p;
		lb[i] *= 2;
		rb[i] *= 2;
		ev[lb[i]].pb(i);
		ev[rb[i]].pb(i);
	}
	
	int q;
	scanf("%d", &q);
	
	for (int i = 1; i <= q; i++)
	{
		int a;
		scanf("%d %d", &a, qcost + i);
		
		ev[2 * a + 1].pb(-i);
	}
	
	
	rec(0, maxn - 1);
	
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	
	
	return 0;
}