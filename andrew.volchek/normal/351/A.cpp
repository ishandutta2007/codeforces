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

const int maxn = 4005;

int a[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int x;
		scanf("%d.%d", &x, a + i);
		if (x < 0)
			a[i] = 1000 - a[i];
		cnt += a[i] == 0;
	}
	cnt = min(n, cnt);	
	int sum = 1000 * n;
	for (int i = 0; i < 2 * n; i++)
		sum -= a[i];
	int ans = abs(sum);
	for (int i = 0; i < cnt; i++)
	{
		sum -= 1000;
		ans = min(ans, abs(sum));
	}
	printf("%d.%03d", ans / 1000, ans % 1000);	
	return 0;
}