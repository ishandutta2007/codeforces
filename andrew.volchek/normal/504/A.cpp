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

const int maxn = 1 << 17;

int deg[maxn], a[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d %d", deg + i, a + i);
		
	vector < pair < int, int > > ans;
	
	queue < int > q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 1)
			q.push(i);
			
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		if (deg[v] == 0)
			continue;
			
		int u = a[v];
		ans.pb(mp(v, u));
		a[u] ^= v;
		deg[u]--;
		
		if (deg[u] == 1)
			q.push(u);
	}
	
	printf("%d\n", ans.size());
	
	for (auto x : ans)
		printf("%d %d\n", x.fst, x.snd);
	
	
	return 0;
}