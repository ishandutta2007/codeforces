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

int used[maxn];
int a[maxn];

int n;

void dfs(int v)
{
	used[v] = 1;
	if (v != n && !used[v + a[v]])
		dfs(v + a[v]);
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	int t;
	cin >> n >> t;
	
	for (int i = 1; i <= n - 1; i++)
		cin >> a[i];
		
	dfs(1);
	
	if (used[t])
		puts("YES");
	else
		puts("NO");
	
	
	
	return 0;
}