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

const int maxn = 1000005;
vector < int > rest[maxn][2];
vector < int > ans;


int maxRest[maxn];
int minRest[maxn];

set < int > currRest;
int p = 1;

void die()
{
	printf("IMPOSSIBLE");
	exit(0);
}


int was[105][105];
vector < int > f[105][105];

bool dfs(int l, int r)
{
	//cerr << l << " " << r << endl;
	
	if (was[l][r] != -1)
	{
		for (int x : f[l][r])
			ans.pb(x);
		return was[l][r];
	}
	
	if (l == r)
	{
		ans.pb(l);
		f[l][r].pb(l);
		return was[l][r] = (rest[l][0].empty() && rest[l][1].empty());
	}
	
	//for (int x : rest[l][0])
	//	cerr << x << endl;
	
	
	for (int lend = l + 1; lend <= r + 1; lend++)
	{
		bool good = true;
		for (int x : rest[l][0])
			good &= l + 1 <= x && x < lend;
		for (int x : rest[l][1])
			good &= lend <= x && x < r + 1;
			
		if (good)
		{
			//cerr << lend << endl;
			bool res = true;
			
			int prv = ans.size();
			
			if (l + 1 <= lend - 1)
				res = dfs(l + 1, lend - 1);
			//ans.pb(l);
			if (res)
			{
				ans.pb(l);
				if (lend <= r)
					res = dfs(lend, r);
				
				if (res)
				{
					if (l + 1 <= lend - 1)
						for (int x : f[l + 1][lend - 1])
							f[l][r].pb(x);
					f[l][r].pb(l);
					if (lend <= r)
						for (int x : f[lend][r])
							f[l][r].pb(x);
					return was[l][r] = true;
				}
			}
			
			while (ans.size() != prv)
					ans.pop_back();
		}
	}
	
	return was[l][r] = false;
}

char s[100];

int main()
{
//	srand(time(NULL));
//	gen();
//	freopen("a.in", "r", stdin);
	
	int n, c;
	scanf("%d %d\n", &n, &c);
	for (int i = 0; i < c; i++)
	{
		int u, v;
		scanf("%d %d %s\n", &u, &v, s);
		if (s[0] == 'L')
			rest[u][0].pb(v);
		else
			rest[u][1].pb(v);
	}
	for (int i = 0; i < 105; i++)	
		for (int j = 0; j < 105; j++)
			was[i][j] = -1;
	if (!dfs(1, n))
		die();

	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	printf("\n");
	

	return 0;
}