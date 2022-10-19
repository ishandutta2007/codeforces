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
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 1e6 + 500;
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
int n;
lli a[N];
pair <lli, lli> b[N];
int main()
{
	fastio;
	cout.precision(13);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = MP(a[i], 1LL);
		int j = i + 1;
		while (j < n)
		{
			if (b[j].fr * b[i].sc < b[i].fr * b[j].sc)
			{
				lli sm = b[i].fr + b[j].fr;
				lli ss = b[i].sc + b[j].sc;
				b[i] = MP(sm, ss);
				//b[j] = MP(sm, ss);
				j = i + b[i].sc;
			}
			else break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		ld a = b[i].fr;
		ld c = b[i].sc;
		for (int j = 0; j < c; j++)
		{
			cout << a / c << "\n";
			i++;
		}
		i--;
	}
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