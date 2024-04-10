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


const int N = 2e6 + 20;
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

string s, t;
lli p[N], pr[N];
int qn, pat;
int main()
{
	fastio;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	if (n > m) return cout << 0, 0;
	p[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		p[i] = p[i - 1] * 31LL;
		p[i] %= mod;
	}
	pr[0] = t[0];
	for (int i = 1; i <= m; i++)
	{
		pr[i] = pr[i - 1] + p[i] * 1LL * (lli)t[i];
		pr[i] %= mod;
	}
	for (int i = 0; i < n; i++)	if (s[i] == '1') qn++;
	//cout << n - qn << endl;
	for (int i = 1; i < m; i++)
	{
		if (m <= qn * i) break;
		if ((m - qn * i) % (n - qn) == 0)
		{
			bool bl = true;
			int ss = (m - qn * i) / (n - qn);
			if (ss <= 0) continue;
			lli zr = -1, mk = -1;
			int i1 = 0;
			for (int j = 0; j < n; j++)
			{
				if (s[j] == '1')
				{
					lli sm = pr[i1 + i - 1];
					if (i1) sm -= pr[i1 - 1];
					if (sm < 0) sm += mod;
					sm *= p[m - i1 - i];
					sm %= mod;
					if (mk == -1) mk = sm;
					else if (mk != sm) bl = false;
					i1 += i;
				}
				else
				{
					lli sm = pr[i1 + ss - 1];
					if (i1) sm -= pr[i1 - 1];
					if (sm < 0) sm += mod;
					sm *= p[m - i1 - ss];
					sm %= mod;
					if (zr == -1) zr = sm;
					else if (zr != sm) bl = false;
					i1 += ss;
				}
			}
			if (zr == mk) bl = false;
			pat += bl;
		}
	}
	cout << pat << endl;
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