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

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 1; i < 4100000; i++)
	{
		ll x = 3LL * i * (i + 1) / 2;
		if ((n + i) % 3 == 0 && n + i >= x)
			ans++;
	}
	cout << ans;
	return 0;
}