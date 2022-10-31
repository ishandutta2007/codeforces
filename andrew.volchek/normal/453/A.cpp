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


ld bpow(ld x, int n)
{
	ld res = 1;
	while (n)
	{
		if (n & 1)
			res = res * x;
		x = x * x;
		n >>= 1;
	}
	return res;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	cin >> m >> n;
	
	ld ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans += (ld)i * (bpow((ld)i / m, n) - bpow((ld)(i - 1) / m, n) );;
	}
	cout.precision(7);
	cout << fixed << ans << endl;
	
	return 0;
}