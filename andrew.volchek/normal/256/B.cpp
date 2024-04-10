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



int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	ll n, x, y, c;
	cin >> n >> x >> y >> c;
	//n = 4, x = 1, y = 1, c = 16;
	
	ll lo = -1, hi = 2 * n + 3;
	
	while (hi - lo > 1)
	{
		ll mid = (lo + hi) >> 1;
		
		ll cnt = (mid + 1) * (mid + 2) * 2 - (mid + 1) * 4 + 1;
		
		if (n - x < mid)
		{
			ll t = mid - (n - x);
			cnt -= t * t;
		}
		
		if (n - y < mid)
		{
			ll t = mid - (n - y);
			cnt -= t * t;
		}
		
		if (x - 1 < mid)
		{
			ll t = mid - (x - 1);
			cnt -= t * t;
		}
		
		if (y - 1 < mid)
		{
			ll t = mid - (y - 1);
			cnt -= t * t;
		}
		
		if (x + y <= mid)
		{
			ll t = mid - (x + y) + 1;
			cnt += t * (t + 1) / 2;
		}
		
		if ((n - x + 1) + y <= mid)
		{
			ll t = mid - ((n - x + 1) + y) + 1;
			cnt += t * (t + 1) / 2;
		}
		
		if ((n - x + 1) + (n - y + 1) <= mid)
		{
			ll t = mid + 1 - ((n - x + 1) + (n - y + 1)) ;
			cnt += t * (t + 1) / 2;
		}
		
		if (x + (n - y + 1) <= mid)
		{
			ll t = mid - (x + (n - y + 1)) + 1;
			cnt += t * (t + 1) / 2;
		}
		
		if (cnt >= c)
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}
	
	cout << hi << endl;
	
	return 0;
}