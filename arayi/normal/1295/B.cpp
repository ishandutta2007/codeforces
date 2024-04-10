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
 
lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
 
 
const int N = 2e5 + 20;
const lli mod = 1e9 + 7;
 
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
int t, n, x;
int pr[N];
string s;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> x >> s;
		int sm = 0, pat = 0;
		if (x == 0) pat++;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0') sm++;
			else sm--;
			pr[i] = sm;
		}
		if (pr[n - 1] > 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (pr[i] <= x && (x - pr[i]) % pr[n - 1] == 0)
				{
					pat++;
				}
			}
		}
		else if (pr[n - 1] < 0)
		{
			for (int i = 0; i < n; i++)
			{
				if (pr[i] >= x && (pr[i] - x) % abs(pr[n - 1]) == 0)
				{
					pat++;
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (pr[i] == x) pat = -1;
			}
		}
		cout << pat << endl;
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