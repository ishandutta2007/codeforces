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


const lli N = 1e6 + 500;
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

int i1;
lli n, m, k;
vector <pair<int, string> > pat;
int main()
{
	fastio;
	cin >> n >> m >> k;
	int k1 = k;
	if (m == 1)
	{

		if (k > 2 * (n - 1)) cout << "NO";
		else
		{
			cout << "YES\n";
			if (k > n - 1)
			{
				cout << 2 << endl;
				cout << n - 1 << " D\n";
				cout << k - n + 1 << " U\n";
			}
			else
			{
				cout << 1 << endl;
				cout << k << " D\n";
			}
		}
		return 0;
	}
	if (n == 1)
	{
		if (k > 2 * (m - 1)) cout << "NO";
		else
		{
			cout << "YES\n";
			if (k > m - 1)
			{
				cout << 2 << endl;
				cout << m - 1 << " R\n";
				cout << k - m + 1 << " L\n";
			}
			else
			{
				cout << 1 << endl;
				cout << k << " R\n";
			}
		}
		return 0;
	}
	if (k > ((4 * m * n) - (2 * n) - (2 * m)))
	{
		cout << "NO\n";
		return 0;
	}
	pat.PB(MP(min(k, m - 1), "R"));
	k -= min(m - 1, k);
	if (k)
	{
		pat.PB(MP(min(k, m - 1), "L"));
		k -= min(m - 1, k);
	}
	if (k)
	{
		pat.PB(MP(min(k, n - 1), "D"));
		k -= min(k, n - 1);
	}
	if (k)
	{
		pat.PB(MP(min(k, m - 1), "R"));
		k -= min(m - 1, k);
	}
	while (k > 0)
	{
		i1++;
		if (i1 > n - 1)
		{
			cout << "NO\n";
			return 0;
		}
		if (k >= 3)
		{
			pat.PB(MP(min(k / 3, m - 1), "UDL"));
			k -= min((k / 3) * 3, 3 * (m - 1));
		}
		else if (k == 2) pat.PB(MP(1, "UD")), k = 0;
		else if (k == 1) pat.PB(MP(1, "U")), k = 0;
		
		if (k) pat.PB(MP(1, "U")), k--;
		if (i1 == n - 1 && k == 1) pat.PB(MP(1, "D")), k--;
		if (k) pat.PB(MP(min(k, m - 1), "R")), k -= min(k, m - 1);
	}
	cout << "YES\n";
	if (pat.size() > 3000)
	{
		while (1)
		{
			int a = 0;
		}
	}
	int sum = 0;
	cout << pat.size() << endl;
	for (auto p : pat)
	{
		//cout << p.fr << " " << p.sc << endl;
		sum += p.fr * p.sc.length();
	}
	if (sum != k1)
	{
		while (1) int a = 1;
	}
	for (auto p : pat)
	{
		if (p.fr)
		{
			cout << p.fr << " " << p.sc << endl;
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