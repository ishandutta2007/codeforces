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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

ll gcd(ll a, ll b)
{
	return a ? gcd(b % a, a) : b;
}

ll solve(int n, ll a, ll b)
{
	ll x = a / gcd(a, b) * b;
	ll res = 0;
	
	for (int i = max(1, n - 1000); i <= n; i++)
	{
		ll curr = x / gcd(x, i) * i;
		res = max(res, curr);
	}
	
	return res;
}


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	ll ans = 0;
	
	for (int i = n; i >= max(1, n - 10); i--)
	{
		for (int j = i; j >= max(1, i - 10); j--)
		{
			ans = max(ans, solve(n, i, j));
		}
	}
	
	cout << ans;
	
	
	return 0;
}