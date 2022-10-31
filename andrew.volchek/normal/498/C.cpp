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
#define y1 _y1

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 105;

int a[maxn];
int p[32000];
vector < int > pr;

int gcd(int a, int b)
{
	return a ? gcd(b % a, a) : b;
}


vector < int > g[maxn * 40];

vector < pair < int, int > > f[maxn];


int used[maxn * 40];
int mt[maxn * 40];

int currUsed = 1;

int kuhn(int v)
{
	if (used[v] == currUsed)
	  return 0;
	used[v] = currUsed;
	
	for (int i = 0; i < g[v].size(); i++) 
	{
		int to = g[v][i];
		if (mt[to] == -1 || kuhn (mt[to]))
		{
			mt[to] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	for (ll i = 2; i < 32000; i++)
	{
		if (p[i])
			continue;
		pr.pb(i);
		for (ll j = i * i; j < 32000; j += i)
			p[j] = 1;
	}
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	int vCnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int g = a[i];
		for (int x : pr)
		{
			while (g % x == 0)
			{
				f[i].pb(mp(x, vCnt++));
				g /= x;
			}
		}
		if (g > 1)
			f[i].pb(mp(g, vCnt++));
	}
	
	
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (u % 2 == 0)
			swap(u, v);
			
		set < int > used;
		
		for (auto x : f[u])
		{
			for (auto y : f[v])
			{
				//if (used.count(y.snd))
				//	continue;
				if (x.fst != y.fst)
					continue;
				g[x.snd].pb(y.snd);
				//used.insert(y.snd);
				//break;
			}
		}
	}
	
	for (int i = 0; i < maxn * 40; i++)
		mt[i] = -1;
		
	for (int i = 0; i < vCnt; i++)
	{
		currUsed++;
		kuhn(i);
	}
	
	int ans = 0;
	
	for (int i = 0; i < maxn * 40; i++)
		if (mt[i] != -1)
			ans++;
			
	cout << ans << endl;
	
	return 0;
}