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

ll m, l, r, k;

struct matr
{
	ll a[2][2];
	matr operator * (const matr &b)
	{
		matr res;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				res.a[i][j] = 0;
				for (int h = 0; h < 2; h++)
					res.a[i][j] = (res.a[i][j] + a[i][h] * b.a[h][j]) % m;
			}
		}
		return res;
	}
};

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	cin >> m >> l >> r >> k;
	ll ans = 0;
	l--;
	vector < ll > v;
	ll a = 1;
	while (true)
	{
		ll b = l / a;
		if (!b)
			break;
		ll c = l / b;
		v.pb(a);
		v.pb(c);
		a = c + 1;
	}
	a = 1;
	while (true)
	{
		ll b = r / a;
		if (!b)
			break;
		ll c = r / b;
		v.pb(a);
		v.pb(b);
		a = c + 1;
	}
	for (ll x : v)
		if (r / x - l / x >= k)
			ans = max(ans, x);	
	ans--;
	matr res;
	res.a[0][0] = res.a[1][1] = 1;
	res.a[0][1] = res.a[1][0] = 0;
	matr x;
	x.a[0][0] = x.a[0][1] = x.a[1][0] = 1;
	x.a[1][1] = 0;
	while (ans)
	{
		if (ans & 1)
			res = (res * x);
		x = x * x;
		ans >>= 1;
	}
	cout << res.a[0][0] % m;
	return 0;
}