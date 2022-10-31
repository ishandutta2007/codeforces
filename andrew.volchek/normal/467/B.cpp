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

int a[1005];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m + 1; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (__builtin_popcount(a[i] ^ a[m]) <= k)
			ans++;
	cout << ans;
	return 0;
}