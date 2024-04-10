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

const int maxn = 300005;
int a[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
		
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			ans += (ll)a[i] * (i + 2);
		else
			ans += (ll)a[i] * (i + 1);
	}
	cout << ans;
	return 0;
}