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
int a[N];
bool col[N];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		itn mx = 0;
		vector <int> sm;
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (!col[a[i]])
			{
				col[a[i]] = true;
				mx++;
				sm.ad(a[i]);
			}
		}
		if (mx > k)
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= k; i++)
		{
			if ((int)sm.size() == k) break;
			if (!col[i]) sm.ad(i);
		}
		cout << k * n << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				cout << sm[j] << " ";
			}
		}
		cout << endl;
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