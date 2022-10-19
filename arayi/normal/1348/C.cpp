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


const int N = 1e4 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 238;
const ld e = 1e-6;

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
ostream& operator<<(ostream& c, pir a)
{
	c << a.fr << " " << a.sc;
	return c;
}




int t, n, k;
string s;
int col[30];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;
		int mn = 30;
		int sm = 0;
		memset(col, 0, sizeof(col));
		for (int i = 0; i < s.length(); i++)
		{
			col[s[i] - 'a']++;
			mn = min(mn, s[i] - 'a');
		}
		if (col[mn] < k)
		{
			int sum = 0;
			for (int i = mn; i < 30; i++)
			{
				sum += col[i];
				if (sum >= k)
				{
					cout << char('a' + i) << endl;
					break;
				}
			}
			continue;
		}
		string pat;
		pat += char('a' + mn);
		col[mn] -= k;
		for (int i = 0; i < 30; i++)
		{
			if (col[i])sm++, mn = i;
		}

		if (sm == 1)
		{
			while (col[mn] > 0)
			{
				pat += 'a' + mn;
				col[mn] -= k;
			}
			cout << pat << endl;
		}
		else
		{
			for (int i = 0; i < 30; i++)
			{
				for (int j = 0; j < col[i]; j++)
				{
					pat += char('a' + i);
				}
			}
			cout << pat << endl;
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