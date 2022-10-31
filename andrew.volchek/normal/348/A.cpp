#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

const int maxn = 100005;
int a[maxn];
int n;

bool can(ll x)
{
	ll free = 0;
	if (x < a[0])
		return false;
	for (int i = 0; i < n-1; i++)
	{
		ll rem = max(0LL, x - max((ll)a[i] - free, 0LL));
		x -= rem;
		free += rem;
	}
	
	if ((ll)a[n-1] > free)
		return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	ll lo = 0;
	ll hi = 1e12;
	while (hi - lo > 1)
	{
		ll mid = (lo + hi) / 2;
		if (can(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi;

	return 0;
}