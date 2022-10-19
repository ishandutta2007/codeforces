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


const int N = 3e5 + 20;
lli mod = 1e9 + 7;
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



int t;
lli n, l, r;
vector <int> fp, pat;
void sm(int i1)
{
	for (int i = i1 + 1; i <= n; i++)
	{
		pat.ad(i1);
		pat.ad(i);
	}
}
void sm1(lli l, lli r)
{
	for (lli i = l - n * (n - 2LL) - 2LL; i <= r - n * (n - 2LL) - 2LL; i++)
	{
		cout << fp[i] << " ";
	}
	
}
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> l >> r;
		lli i1, n1, sum;
		i1 = 1, n1 = n, sum = 0;
		pat.clear();
		for (; i1 <= n; i1++)
		{
			if (sum + 2LL * (n1 - 1LL) >= l) break;
			sum += 2LL * (n1 - 1LL);
			n1--;
		}
		//cout << i1 << endl;
		while (sum + (lli)pat.size() < min(n * (n - 1LL), r))
		{
			sm(i1);
			i1++;
			//cout << pat.size() << endl;
		}
		//cout << pat.size() << endl;
		//cout << "SM" << endl;
		lli sum1 = sum;
		while (sum < min(n * (n - 1LL), r))
		{
			if (sum >= l - 1LL) cout << pat[sum - sum1] << " ";
			sum++;
		}
		if (r > (n * (n - 1LL))) cout << 1;
		cout << "\n";
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