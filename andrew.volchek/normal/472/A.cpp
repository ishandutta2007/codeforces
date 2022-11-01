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

int p[1000005];

int main()
{
	//freopen("a.in", "r", stdin);
	for (ll i = 2; i < 1000005; i++)
	{
		if (p[i])
			continue;
		for (ll j = i * i; j < 1000005; j += i)
			p[j] = 1;
	}
	
	int n;
	cin >> n;
	
	for (int i = 2; i < n; i++)
	{
		if (p[i] && p[n - i] && n - i > 1)
		{
			cout << i << " " << n - i << endl;
			return 0;
		}
	}
	
	return 0;
}