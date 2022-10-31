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

ll f[100];
ll len[100];


pair < ll, ll > dist(ll x, int k)
{
	if (k == 0)
		return mp(0, 0);
	else if (k == 1)
		return mp(x, 1 - x);
		
	if (x < f[k - 1])
	{
		pair < ll, ll > a = dist(x, k - 1);
		pair < ll, ll > b = mp(min(a.fst, a.snd + 2), min(a.snd, a.fst + 2));
		b.snd = min(b.fst, b.snd) + 1 + len[k - 2];
		return b;
	}
	else
	{
		pair < ll, ll > a = dist(x - f[k - 1], k - 2);
		a.fst++;
		return a;
	}
}

ll solve(ll u, ll v, int k, ll g)
{
	if (k == 0)
		return 0;
	else if (k == 1)
		return 1;
	
	if (u < f[k - 1] && v < f[k - 1])
		return solve(u, v, k - 1, 2);
	else if (u >= f[k - 1] && v >= f[k - 1])
		return solve(u - f[k - 1], v - f[k - 1], k - 2, g + 1);
		
	pair < ll, ll > a = dist(u, k - 1);
	pair < ll, ll > b = dist(v - f[k - 1], k - 2);
	
	ll res = min(a.fst, a.snd) + 1 + b.fst;
	res = min(res, min(a.fst, a.snd + 2) + b.snd + g);
		
	return res;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	f[0] = 1;
	f[1] = 2;
	len[0] = 0;
	len[1] = 1;
	
	for (int i = 2; i <= 80; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		len[i] = 1 + len[i - 2];
		//cerr << f[i] << endl;
	}
	
	int n, k;
	cin >> n >> k;
	ll g = 1e18;
	if (k > 80)
	{
		k = 80;
		g = 2;
	}
	
	for (int i = 0; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		
		if (u > v)
			swap(u, v);
			
		cout << solve(u, v, k, g) << endl;
	}
	
	return 0;
}