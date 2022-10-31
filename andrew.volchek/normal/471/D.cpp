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

const int maxn = 4000005;
int a[maxn], b[maxn];
ll c[maxn];
int pr[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, w;
	scanf("%d %d", &n, &w);
	
	if (w == 1)
	{
		cout << n;
		return 0;
	}
	
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < n; i++)
		scanf("%d", b + i);
	for (int i = 0; i < w; i++)
		scanf("%d", a + i);
		
	int pos = 0;
	for (int i = 0; i + 1 < w; i++)
		c[pos++] = (ll)a[i] - a[i + 1];
		
	c[pos++] = 1e18;
	
	for (int i = 0; i + 1 < n; i++)
		c[pos++] = (ll)b[i] - b[i + 1];
		
	int ans = 0;
	
	for (int i = 1; i < pos; i++)
	{
		int j = pr[i - 1];
		while (j > 0 && c[j] != c[i]) j = pr[j - 1];
		if (c[j] == c[i])
			j++;
		pr[i] = j;
		if (i > w && pr[i] == w - 1)
			ans++;			
	}
	
	cout << ans;
	return 0;
}