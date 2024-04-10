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

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 3e5 + 30;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 150;

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
struct li
{
	lli a[4];
	const lli sm = 1e9;
	li()
	{
		a[0] = a[1] = a[2] = a[3] = 0;
	}
	li operator+(li b)
	{
		li c;
		c.a[3] = a[3] + b.a[3];
		c.a[2] = a[2] + b.a[2] + c.a[3] % sm;
		c.a[1] = a[1] + b.a[1] + c.a[2] % sm;
		c.a[0] = a[0] + b.a[0] + c.a[1] % sm;
		for (int i = 0; i < 4; i++)
		{
			c.a[i] %= sm;
		}
	}
	li operator=(string b)
	{
		li c;
		int i1 = 0;
		lli tas = 1;
		reverse(b.begin(), b.end());
		for (int i = 0; i < b.length(); i++)
		{
			if (i % 9 == 0) tas = 1, i1++;
			c.a[i1] += tas * 1LL * (b[i] - '0');
			tas *= 10LL;
		}
		for (int i = 0; i < 4; i++)
		{
			a[i] = c.a[i];
		}
	}
	void tp()
	{
		cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
	}
};


int n, k;
vector <int> pat;
int main()
{
	fastio;
	cin >> n >> k;
	if (k > 30)
	{
		for (int i = 0; i < 30; i++)
		{
			if ((1 << i) & n)
			{
				pat.PB((1 << i));
			}
		}
	}
	else
	{
		vector<lli> sm;
		sm.PB(1);
		itn i1 = 0;
		lli sum = 1;
		for (int i = 0; i < 100; i++)
		{
			sm.PB(sum);
			if (sum > n) break;
			sum += sum;
			if (sm.size() > k)
			{
				sum -= sm[i1++];
			}
		}
		for (int i = sm.size() - 1; i >= 0; i--)
		{
			if (sm[i] <= n)
			{
				n -= sm[i];
				pat.PB(sm[i]);
			}
		}
	}
	if (pat.size() == 1) pat.PB(0);
	cout << pat.size() << endl;

	for (int i = 0; i < pat.size(); i++)
	{
		cout << pat[i] << " ";
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