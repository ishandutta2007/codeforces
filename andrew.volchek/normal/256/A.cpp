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

vector < int > a[1000005];
int b[4005];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	vector < int > v;
	
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.pb(x);
		b[i] = x;
		a[x].pb(i);
	}
	
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	
	int ans = 0;
	
	for (int i = 0; i < 1000005; i++)
	{
		ans = max(ans, (int)a[i].size());
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			vector < int > g(a[v[i]].size() + a[v[j]].size());
			merge(a[v[i]].begin(), a[v[i]].end(), a[v[j]].begin(), a[v[j]].end(), g.begin());
			for (int h = 0; h < g.size(); h++)
				g[h] = b[g[h]];
			g.resize(unique(g.begin(), g.end()) - g.begin());
			ans = max(ans, (int)g.size());
		}
	}
	
	cout << ans << endl;
	
	return 0;
}