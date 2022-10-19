#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 3e5 + 500;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 150;

lli bp(lli a, lli b = mod - 2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

struct el
{
	int x, y;
};
int n;
el v[N];
int main()
{
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> v[i].x >> v[i].y;
	if (n & 1)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int j = i + n / 2;
		if (j > n)
			j -= n;
		int i1 = i + 1;
		int j1 = j + 1;
		if (i1 > n)
			i1 -= n;
		if (j1 > n)
			j1 -= n;
		if (!(v[i].x - v[j1].x == v[i1].x - v[j].x && v[i].y - v[j1].y == v[i1].y - v[j].y))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
/*
  __
*(><)*
  \/ /
  ||/
--||
  ||
  /\
 /  \
/    \
*/