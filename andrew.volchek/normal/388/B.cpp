#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>
#include <bitset>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 1005;

vector < int > g[maxn];
int a[maxn][maxn];
int vCnt = 2;

int rec(int v, int k)
{
	//cerr << vCnt << endl;
	if (k == 1)
	{
		g[v].pb(2);
		return 1;
	}
	
	
		int t = vCnt;
		g[v].pb(vCnt + 1);
		g[v].pb(vCnt + 2);
		g[t+1].pb(vCnt + 3);
		g[t+2].pb(vCnt + 3);
		vCnt += 3;
		int h = rec(t + 3, k / 2) + 2;
		if (k & 1)
		{
			int curr = v;
			for (int i = 0; i < h-1; i++)
			{
				g[curr].pb(vCnt + 1);
				curr = vCnt + 1;
				vCnt++;			
			}
			g[curr].pb(2);
		}
	return h;
}

int main()
{
	//freopen("a.in", "r", stdin);
	int k;
	cin >> k;
	
	rec(1, k);
	
	int n = vCnt;
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			int to = g[i][j];
			a[i][to] = 1;
			a[to][i] = 1;
		}
	}
	
	cout << n << endl;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j])
				printf("Y");
			else
				printf("N");
		}
		printf("\n");
	}
	
	
	return 0;
}