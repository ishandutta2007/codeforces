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
int q, n;
string s, t;
int haj[N][30];
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> s >> t;
		n = s.length();
		for (int i = 0; i < 26; i++)
		{
			haj[n][i] = -1;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < 26; j++)
			{
				haj[i][j] = haj[i + 1][j];
			}
			haj[i][s[i] - 'a'] = i;
		}
		int pat = 0, i1 = -1;
		bool bl = false;
		for (int i = 0; i < t.length(); i++)
		{
			if (haj[0][t[i] - 'a'] == -1)
			{
				bl = true;
			}
		}
		if (bl) cout << -1 << endl;
		else
		{
			for (int i = 0; i < t.length(); i++)
			{
				if (haj[i1 + 1][t[i] - 'a'] == -1)
				{
					i1 = -1;
					pat++;
					i--;
				}
				else
				{
					i1 = haj[i1 + 1][t[i] - 'a'];
				}
			}
			cout << pat + 1 << endl;
		}
		
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