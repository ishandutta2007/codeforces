#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull long long
#define fst first
#define snd second
#define ld long double

const int maxn = 100005;
vector < int > g[maxn];
ull cnt[maxn];
ull need[maxn];
ull dpCnt[maxn];

ull gcd(ull a, ull b)
{
	return a ? gcd(b % a, a) : b;
}

void dfsCnt(int v, int p)
{
	dpCnt[v] = cnt[v];
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
		{
			dfsCnt(g[v][i], v);
			dpCnt[v] += dpCnt[g[v][i]];
		}
}

bool bad = false;
void reportBad()
{
	cout << dpCnt[1];
	exit(0);
}

void dfs(int v, int p)
{
	if (g[v].size() == 1 && p != 0)
	{
		need[v] = 1;
		return;
	}
	
	int lstInd;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
		{
			dfs(g[v][i], v);
			lstInd = i;
		}
			
	
	need[v] = need[g[v][lstInd]];;
	if (need[v] > dpCnt[v])
		reportBad();
	for (int i = 0; i < lstInd; i++)
		if (g[v][i] != p)
		{
			ull _g = gcd(need[v], need[g[v][i]]);
			if (need[v] * (need[g[v][i]] / _g) > dpCnt[v])
				reportBad();
			need[v] *= (need[g[v][i]] / _g);
		}
	if (p != 0 && need[v] * (ull)(g[v].size()-1) > dpCnt[v])
		reportBad();
	if (p == 0 && need[v] * (ull)(g[v].size()) > dpCnt[v])
		reportBad();	
		
	if (p == 0)
		need[v] *= (ull)(g[v].size()) ;
	else
		need[v] *= (ull)(g[v].size()-1) ;
}

ull multiplier = 1e12;

void dfsMult(int v, int p, ll must)
{
	multiplier = min(multiplier, dpCnt[v] / must);
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
		{
			if (p == 0)
				dfsMult(g[v][i], v, must / (ll)(g[v].size()));
			else
				dfsMult(g[v][i], v, must / (ll)(g[v].size()-1));
		}
}

ull ans = 0;

void dfsAns(int v, int p, ull must)
{
	
	
	if (g[v].size() == 1 && p != 0)
	{
		//cerr << cnt[v] << " " << must << endl;
		ans += cnt[v] - must;
		return;
	}
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != p)
		{
			if (p == 0)
				dfsAns(g[v][i], v, must / (ll)(g[v].size()));
			else
				dfsAns(g[v][i], v, must / (ll)(g[v].size()-1));
		}
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[i+1] = x;
	}
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfsCnt(1, 0);
	dfs(1, 0);
	dfsMult(1, 0, need[1]);
	/*cerr << endl;
	for (int i = 1; i <= n; i++)
		cerr << need[i] << endl;*/
	dfsAns(1, 0, multiplier * need[1]);
	cout << ans;

	return 0;
}