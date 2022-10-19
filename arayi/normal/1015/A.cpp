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
#include <climits>
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


const lli N = 5e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 150;
const ld e = 74e-9;

lli bp(lli a, lli b =	- 2LL)
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


int n,m;
int a[N];
vector<int>pat;
int main()
{
	fastio;
	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		for (int j = l; j <= r; j++)
		{
			a[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (a[i] == 0) pat.PB(i);
	}
	cout << pat.size() <<endl;
	for (auto p : pat) cout << p << " ";
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