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



int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	ll n, m;
	cin >> n >> m;
	ll res = 1, x = 3;
	while (n)
	{
		if (n & 1)
			res = (res * x) % m;
		x = (x * x) % m;
		n >>= 1;
	}
	cout << (res + m - 1) % m << endl;
	return 0;
}