
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
const int magic = 333;

vector < int > g[maxn];
int used[maxn];
int currUsed = 1;
vector < int > visited;

void dfs(int v)
{
	used[v] = currUsed;
	visited.pb(v);
	for (int to : g[v])
		if (used[to] != currUsed)
			dfs(to);
}

vector < vector < int > > smallSets;
vector < int > smallSetsByVertex[maxn];
vector < vector < int > > bigSets;
vector < pair < int, int > > queries[maxn];
int ans[maxn];

int n;

int cnt[maxn];

void processSmallSets()
{
	for (int i = 0; i < n; i++)
	{
		currUsed++;
		vector < int > was;
		
		for (int j = 0; j < smallSetsByVertex[i].size(); j++)
		{
			for (int x : smallSets[smallSetsByVertex[i][j]])
			{
				if (used[x] != currUsed)
				{
					was.pb(x);
					used[x] = currUsed;
				}
				
				cnt[x]++;
			}
		}
		
		for (auto q : queries[i])
		{
			ans[q.snd] += cnt[q.fst];
		}
		
		for (int x : was)
			cnt[x] = 0;
	}
}


int color[maxn];


void processBigSets()
{
	for (int i = 0; i < bigSets.size(); i++)
	{
		vector < int > was;
		currUsed++;
		
		for (int x : bigSets[i])
		{
			if (used[x] != currUsed)
			{
				used[x] = currUsed;
				was.pb(x);
			}
			
			color[x] = 1;
		}
		
		for (int i = 0; i < n; i++)
		{
			if (!color[i])
				continue;
			for (auto q : queries[i])
			{
				ans[q.snd] += color[q.fst];
			}
		}
		
		for (int x : was)
			color[x] = 0;
	}
}

vector < pair < int, int > > edges[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		u--;
		v--;
		c--;
		if (u > v)
			swap(u, v);
		edges[c].pb(mp(u, v));
	}
	
	for (int i = 0; i < maxn; i++)
	{
		if (edges[i].empty())
			continue;
			
		vector < int > need;
			
		for (auto e : edges[i])
		{
			need.pb(e.fst);
			need.pb(e.snd);
			
			
			g[e.fst].pb(e.snd);
			g[e.snd].pb(e.fst);
		}
		
		currUsed++;
		
		for (int x : need)
		{
			if (used[x] == currUsed)
				continue;
			
			visited.clear();
			dfs(x);
			
			for (int x : visited)
				g[x].clear();
			
			if (visited.size() > magic)
				bigSets.pb(visited);
			else
			{
				smallSets.pb(visited);
				for (int x : visited)
				{
					smallSetsByVertex[x].pb(smallSets.size() - 1);
				}
			}
		}
	}
	
	int q;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		
		u--;
		v--;
		
		if (u > v)
			swap(u, v);
			
		queries[u].pb(mp(v, i));
	}
	
	processBigSets();
	processSmallSets();
	
	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	
	

	return 0;
}