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
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 3e5 + 30;
int mod = 1000;

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
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n;
string s;
int pr[N], a[N], nw[N];
lli ans;
int dz[N], aj[N];
int main()
{
	fastio;
	cin >> s;
	n = s.length();
	//mod = sqrt(n);
	for (int i = 1; i <= n; i++)
	{
		a[i] = s[i - 1] - '0';
		pr[i] = pr[i - 1] + a[i];
		nw[i] = i;
	}
	for (int i = 0; i <= n; i++)
	{
		aj[pr[i]] = i;
	}
	for (int i = n; i >= 0; i--)
	{
		dz[pr[i]] = i;
	}
	for (int x = 1; x < (n / mod); x++)
	{
		unordered_map <int, int> mp;
		for (int i = 0; i <= n; i++)
		{
			nw[i] -= pr[i];
			ans += mp[nw[i]];
			mp[nw[i]]++;
		}
	}
	for (int x = 1; x < mod + 1; x++)
	{
		int mn, mx;
		for (int i = 1; i <= n; i++)
		{
			if (pr[i] < x) continue;
			mn = i - aj[pr[i] - x];
			mx = i - dz[pr[i] - x];
			mn = max(mn, (n / mod) * x);
			mx = (mx / x) * x;
			if (mn <= mx)
				ans += (mx - mn) / x + 1LL;
		}
	}
	cout << ans;
	return 0;
}