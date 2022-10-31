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

vector < int > g[maxn];
int used[maxn];
int need[maxn];
vector < int > ans;

bool dfs(int v, bool f)
{
	ans.pb(v);
	int cnt = 1;
	used[v] = 1;
	
	for (int to : g[v])
	{
		if (used[to])	
			continue;
			
		bool res = dfs(to, false);
		ans.pb(v);
		cnt++;
		
		if (res)
		{
			ans.pb(to);
			ans.pb(v);
			cnt++;
		}
	}
	
	if (!f && need[v] != (cnt & 1))
		return true;
	else if (!f && need[v] == (cnt & 1))
		return false;
	else if (f && need[v] == (cnt & 1))
		return false;
	else
	{
		if (ans.size() > 1)
			ans.pop_back();
		return false;
	}
}

int cnt[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	for (int i = 1; i <= n; i++)
		scanf("%d", need + i);
		
	for (int i = 1; i <= n; i++)
		if (need[i])
		{
			dfs(i, true);
			break;
		}
		
	for (int i = 0; i < ans.size(); i++)
	{
		cnt[ans[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		if ((cnt[i] & 1) != need[i])
		{
			cout << -1 << endl;
			return 0;
		}
		
	printf("%d\n", ans.size());
	
	for (int i = 0; i < ans.size(); i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	return 0;
}