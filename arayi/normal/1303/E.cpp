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


const int N = 505;
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

int q;
string s, t;
int dp[N];
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> s >> t;
		int n = s.length(), m = t.length();
		if (n < m)
		{
			cout << "NO\n";
			continue;
		}
		bool bl = false;
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i <= n; i++) dp[i] = -1;
			dp[0] = 0;
			for (int i = 0; i < n; i++)
			{
				for (int x = j + 1; x >= 0; x--)
				{
					if (dp[x] >= 0 && dp[x] + j + 1 < m && s[i] == t[dp[x] + j + 1]) dp[x]++;
					if (x > 0 && s[i] == t[x - 1]) dp[x] = max(dp[x], dp[x - 1]);	
				}
			}
			if (dp[j + 1] + j + 1 == m)
			{
				cout << "YES\n";
				bl = true;
				break;
			}
		}
		if (!bl) cout << "NO\n";
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