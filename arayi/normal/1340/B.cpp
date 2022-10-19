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
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };


const int N = 3000 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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
ostream& operator<<(ostream& c, pir a)
{
	c << a.fr << " " << a.sc;
	return c;
}

int n, k;
const string t[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
string s[N];
bool col[N][N];
int sm[N][10];
int stg(string s, string t)
{
	int ret = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1' && t[i] == '0') return -1;
		if (s[i] == '0' && t[i] == '1') ret++;
	}
	return ret;
}

int main()
{
	fastio;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < 10; j++)
		{
			if (stg(s[i], t[j]) != -1)
			{
				sm[i][stg(s[i], t[j])] = 1;
			}
		}
	}
	col[n][0] = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		vector <int> fp;
		for (int j = 0; j < 10; j++)
			if (sm[i][j]) fp.ad(j);
		for (int j = k; j >= 0; j--)
		{
			if (col[i + 1][j])
			{
				for (auto p : fp) col[i][j + p] = true;
			}
		}
	}
	if (!col[0][k]) return cout << -1, 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 10 - 1; j >= 0; j--)
		{
			if (stg(s[i], t[j]) != -1 && k >= stg(s[i], t[j]) && col[i + 1][k - stg(s[i], t[j])])
			{
				cout << j;
				k -= stg(s[i], t[j]);
				break;
			}
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