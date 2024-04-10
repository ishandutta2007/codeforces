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

const ll base[2] = {43LL, 73LL};
const ll mod[2] = {1000000007LL, 1000000009LL};

char str[1000005];

const int maxn = 200005;
vector < int > g[maxn], gt[maxn];;
pair < int, int > val[maxn];
int used[maxn];
int currUsed = 1;
int was[maxn];
vector < int > order;

void dfs(int v, const pair < int, int > x)
{
	val[v] = x;
	used[v] = currUsed;
	for (int to : gt[v])
	{
		if (used[to] == currUsed)
			continue;
		dfs(to, x);
	}
}


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	
	gets(str);
	
	vector < pair < ll, ll > > a;
	vector < pair < int, int > > a2;
	
	int len = strlen(str);
	
	
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
			continue;
		int j = i;
		
		while (j < len && str[j] != ' ') j++;
		pair < ll, ll > curr = mp(0, 0);
		int r = 0, l = 0;
		for (int h = i; h < j; h++)
		{
			curr.fst = (curr.fst * base[0] + tolower(str[h])) % mod[0];
			curr.snd = (curr.snd * base[1] + tolower(str[h])) % mod[1];	
			if (str[h] == 'r' || str[h] == 'R')
				r++;
			l++;
		}
		a2.pb(mp(r, l));
		a.pb(curr);
		i = j - 1;
	}
	
	int m;
	scanf("%d\n", &m);
	
	map < pair < ll, ll >, int > mm;
	int vv = 0;
	
	vector < pair < pair < int, int >, int > > f;
	
	for (int i = 0; i < m; i++)
	{
		gets(str);
		pair < ll, ll > b = mp(0, 0);
		pair < ll, ll > c = mp(0, 0);
		int bR = 0, cR = 0, bLen = 0, cLen = 0;
		int j = 0;
		int len = strlen(str);
		while (str[j] != ' ')
		{
			b.fst = (b.fst * base[0] + tolower(str[j])) % mod[0];
			b.snd = (b.snd * base[1] + tolower(str[j])) % mod[1];
			if (str[j] == 'r' || str[j] == 'R')
				bR++;
			bLen++;
			j++;
		}
		j++;
		while (j < len)
		{
			c.fst = (c.fst * base[0] + tolower(str[j])) % mod[0];
			c.snd = (c.snd * base[1] + tolower(str[j])) % mod[1];
			if (str[j] == 'r' || str[j] == 'R')
				cR++;
			cLen++;
			j++;
		}
		int u, v;
		if (mm.find(b) == mm.end())
		{
			val[vv] = mp(bR, bLen);
			mm[b] = vv;
			f.pb(mp(val[vv], vv));
			vv++;
		}
		if (mm.find(c) == mm.end())
		{
			val[vv] = mp(cR, cLen);
			mm[c] = vv;
			f.pb(mp(val[vv], vv));
			vv++;
		}
		u = mm[b];
		v = mm[c];
		g[u].pb(v);
		gt[v].pb(u);
	}
	
	sort(f.begin(), f.end());
	
	for (int i = 0; i < f.size(); i++)
	{
		int v = f[i].snd;
		if (used[v] == currUsed)
			continue;
		dfs(v, val[v]);
	}
	
	
	pair < ll, ll > ans = mp(0, 0);
	
	for (int i = 0; i < a.size(); i++)
	{
		if (mm.find(a[i]) != mm.end())
		{
			int v = mm[a[i]];
			a2[i] = min(a2[i], val[v]);
		}
		//cerr << a2[i].fst << " " << a2[i].snd << endl;
		ans.fst += a2[i].fst;
		ans.snd += a2[i].snd;
	}
	
	cout << ans.fst << " " << ans.snd;
	
	return 0;
}