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

int a[2005];

int main()
{
	//freopen("a.in", "r", stdin);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	
	ll ans = 0;
	for (int i = 0; i < n; i += k)
	{
		ans += (a[i] - 1) * 2;
	}
	
	cout << ans;
	
	return 0;
}