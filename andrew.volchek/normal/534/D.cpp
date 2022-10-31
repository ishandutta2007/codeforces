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
#include <functional>

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

const int maxn = 200005;

vector < int > a[maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x].pb(i);
	}
	
	vector < int > ans;
	
	int c = 0;
	
	for (int i = 0; i < n; i++)
	{
		while (c >= 0 && a[c].empty()) c -= 3;
		
		if (c < 0)
		{
			puts("Impossible");
			return 0;
		}
		
		ans.pb(a[c].back());
		a[c].pop_back();
		c++;
	}
	
	puts("Possible");
	for (int i = 0; i < n; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	
	
	return 0;
}