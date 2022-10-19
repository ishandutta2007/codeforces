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


const int N = 1e6 + 30;
const lli mod = 998244353;

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


int t;
int n, a, b, mx1, mx2;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		mx1 = 0;
		mx2 = 0;
		cin >> n >> a >> b;
		for (int i = 0; i < a; i++)
		{
			int x;
			cin >> x;
			mx1 = max(mx1, x);
		}
		for (int i = 0; i < b; i++)
		{
			int x;
			cin >> x;
			mx2 = max(mx2, x);
		}
		if (mx1 > mx2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}