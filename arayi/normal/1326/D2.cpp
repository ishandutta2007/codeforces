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
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define pir pair<int, int>
#define itn int
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const lli N = 1e6 + 30;
const lli mod = 998244353;
const ld pi = acos(-1);
const int T = 4e5;
const ld e = 74e-9;

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


int t;
string s;
lli p[N];
lli pr[N], sf[N];
int sm(string s)
{
	int n = s.length();
	pr[0] = s[0];
	for (int i = 1; i < n; i++)
	{
		pr[i] = pr[i - 1] + s[i] * 1LL * p[i];
		pr[i] %= mod;
	}
	sf[n] = 0;
	sf[n - 1] = s[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		sf[i] = sf[i + 1] + s[i] * p[n - i - 1];
		sf[i] %= mod;
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		lli sm = sf[0] - sf[i + 1];
		if (sm < 0)sm += mod;
		if ((pr[i] * p[n - i - 1]) % mod == sm)ret = i + 1;
	}
	return ret;
}
int main()
{
	fastio;
	//cin >> s;
	//cout << sm(s) << endl;
	cin >> t;
	p[0] = 1;
	for (int i = 1; i < N; i++)
	{
		p[i] = p[i - 1] * 31LL;
		p[i] %= mod;
	}
	while (t--)
	{
		cin >> s;
		string t = s;
		reverse(all(s));
		if (t == s)
		{
			cout << t << "\n";
			continue;
		}
		reverse(all(s));
		int n = s.length();
		int x;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != s[n - i - 1])
			{
				x = i;
				break;
			}
		}
		int a = sm(s.substr(x, n - 2 * x));
		reverse(all(s));
		int b = sm(s.substr(x, n - 2 * x));
		reverse(all(s));
		//cout << a << " " << b << endl;
		if (a > b)
		{
			cout << s.substr(0, x) << s.substr(x, a) << s.substr(n - x, x) << "\n";
		}
		else
		{
			cout << s.substr(0, x) << s.substr(n - x - b, x + b) << "\n";
		}
	}
	return 0;
}