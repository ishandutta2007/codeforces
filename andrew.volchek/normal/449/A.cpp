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
	ll n, m, k;
	cin >> n >> m >> k;
	
	ll ans = 0;
	
	if (n - 1 + m - 1 < k)
	{
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < 2; i++)
	{
		ll a = 1;
		while (a <= n)
		{
			ll b = n / a;
			ll c = n / b;
			
			if (a - 1 <= k)
			{
				ans = max(ans, b * (m / (k - a + 2)));
			}
			
			if (c - 1 <= k)
			{
				ans = max(ans, b * (m / (k - c + 2)));
			}
			
			a = c + 1;
		}
		
		swap(n, m);
	}
	
	cout << ans << endl;
	
	return 0;
}