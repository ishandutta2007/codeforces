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
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pir pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 5000 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
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


int n, k, sm = mod;
string s, pat;
int a[10];
int main()
{
	fastio;
	cin >> n >> k >> s;
	for (int i = 0; i < s.length(); i++)
	{
		a[s[i] - '0']++;
	}
	for (int i = 0; i < 10; i++)
	{
		int k1 = k, sum = 0;
		string s1 = s;
		k1 -= a[i];
		if (k1 <= 0)
		{
			cout << 0 << endl << s << endl;
			return 0;
		}
		for (int d = 1; d < 10; d++)
		{
			if (i + d < 10)
			{
				for (int j = 0; j < s1.length(); j++)
				{
					if (k1 == 0) break;
					if (s1[j] - '0' == i + d) s1[j] = i + '0', sum += d, k1--;
				}
			}
			if (i - d >= 0)
			{
				for (int j = s1.length() - 1; j >= 0; j--)
				{
					if (k1 == 0) break;
					if (s1[j] - '0' == i - d) s1[j] = i + '0', sum += d, k1--;
				}
			}
		}
		//cout << s1 << endl;
		if (sum <= sm && k1 == 0)
		{
			if (sum == sm)
				pat = min(pat, s1);
			else
				pat = s1;
			sm = sum;
		}
	}
	cout << sm << endl << pat << endl;
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