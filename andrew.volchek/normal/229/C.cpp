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

const int maxn = 1000005;
int deg[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	ll ans = (ll)n * (n - 1) * (n - 2) / 6;
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		deg[u]++;
		deg[v]++;
		ans -= n - 2;
	}
	
	for (int i = 0; i < maxn; i++)
		ans += (ll)deg[i] * (deg[i] - 1) / 2;
		
	cout << ans << endl;
	
	
	return 0;
}