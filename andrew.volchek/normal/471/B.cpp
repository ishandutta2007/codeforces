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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 2005;
pair < int, int > a[maxn];
int was[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[i] = mp(x, i);
	}
	
	sort(a + 1, a + n + 1);
	
	vector < int > ans[3];
	for (int i = 1; i <= n; i++)
		ans[0].pb(a[i].snd);
	
	bool any = false;
	for (int i = 1; i <= n; i++)
	{
		if (!any && i + 1 <= n && a[i].fst == a[i + 1].fst)
		{
			ans[1].pb(a[i + 1].snd);
			ans[1].pb(a[i].snd);
			was[i] = 1;
			was[i + 1] = 1;
			i++;
			any = true;
			continue;
		}
		ans[1].pb(a[i].snd);
	}
	
	if (!any)
	{
		cout << "NO";
		return 0;
	}
	
	any = false;
	for (int i = 1; i <= n; i++)
	{
		if (!any && i + 1 <= n && a[i].fst == a[i + 1].fst && !(was[i] && was[i + 1]))
		{
			ans[2].pb(a[i + 1].snd);
			ans[2].pb(a[i].snd);
			was[i] = 1;
			was[i + 1] = 1;
			i++;
			any = true;
			continue;
		}
		ans[2].pb(a[i].snd);
	}
	
	
	if (!any)
	{
		cout << "NO";
		return 0;
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j)
				cout << " ";
			cout << ans[i][j];
		}
		
		cout << endl;
	}
	
	
	return 0;
}