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

const int maxn = 200005;

ll a[maxn];
ll b[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m, w;
	scanf("%d %d %d", &n, &m, &w);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	ll lo = 0, hi = 1e10;
	while (hi - lo > 1)
	{
		ll mid = (lo + hi) >> 1;
		for (int i = 0; i < n; i++)
			b[i] = 0;
		ll x = m;
		
		ll curr = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] + curr < mid)
			{
				ll t = mid - (a[i] + curr);
				curr += t;
				x -= t;
				b[i + w - 1] += t;
			}
			
			curr -= b[i];
		}
		
		if (x >= 0)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;
	
	return 0;
}