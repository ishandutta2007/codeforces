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


const int N = 4e5 + 30;
lli mod = 998244353;

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
lli n;
lli f[N];
lli pat;
int main()
{
	fastio;
	cin >> n >> mod;
	f[0] = 1;
	for (lli i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * i;
		f[i] %= mod;
	}
	pat += n * n;
	pat %= mod;
	pat *= f[n - 1];
	pat %= mod;
	for (lli i = 1; i < n; i++)
	{
		lli sm = n - i;
		//cout << sm << " ";
		sm *= (n - i);
		sm %= mod;
		//cout << sm << " ";
		sm *= f[i + 1];
		sm %= mod;
		//cout << sm << " ";
		sm *= f[n - i - 1];
		sm %= mod;
		//cout << sm << " ";
		pat += sm;
		pat %= mod;
		//cout << endl;
	}
	cout << pat << endl;
	return 0;
}