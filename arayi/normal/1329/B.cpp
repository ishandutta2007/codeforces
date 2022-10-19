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
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 2e5 + 20;
lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e1 = 74e-9;

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

int t;
lli dp[40][40];
lli d;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> d >> mod;
		lli pat = 0;
		for (int i = 0; i < 30; i++)
		{
			if ((1 << i) > d) break;
			dp[1][i] = min((1LL << i), d - (1LL << i) + 1);
			dp[1][i] %= mod;
		}
		for (int i = 2; i <= 32; i++)
		{
			if ((1 << (i - 1)) > d) break;
			for (int j = 0; j < 32; j++)
			{
				if ((1 << j) > d) break;
				lli sm = 0;
				for (int x = 0; x < j; x++)
				{
					sm += dp[i - 1][x];
					sm %= mod;
				}
				sm *= 1LL * min((1LL << j), d - (1 << j) + 1);
				sm %= mod;
				dp[i][j] = sm;
			}
		}
		for (int i = 0; i <= 32; i++)
		{
			for (int j = 0; j <= 31; j++)
			{
				pat += dp[i][j];
				pat %= mod;
				dp[i][j] = 0;
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