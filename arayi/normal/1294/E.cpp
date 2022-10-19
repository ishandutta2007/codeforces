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
int mod = 600;

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
int n, m;
vector <int> a[N];
int sm[N];
int pat;
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		a[i].resize(m + 1);
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sm[i] = i + n;
		}
		for (int i = 0; i < n; i++)
		{
			if ((a[i][j] - j) % m == 0)
			{
				int ss = (a[i][j] - j) / m;
				if (ss < n)
				{
					if (i >= ss) sm[i - ss]--;
					else sm[i + n - ss]--;
				}
			}
		}
		int mn = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			mn = min(mn, sm[i]);
		}
		pat += mn;
	}
	cout << pat << endl;
	return 0;
}